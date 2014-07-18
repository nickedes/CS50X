<?php

    // configuration
    require("../includes/config.php"); 

    // render portfolio
    $rows = query("SELECT * FROM shares WHERE id = ?", $_SESSION["id"]);
    
    $positions = [];
	foreach ($rows as $row)
	{
		$stock = lookup($row["symbol"]);
		if ($stock !== false)
		{
		    $positions[] = [
		        "name" => $stock["name"],
		        "price" => $stock["price"],
		        "shares" => $row["shares"],
		        "symbol" => $row["symbol"]
		    ];
		}
	}


    render("portfolio.php", ["positions" => $positions, "title" => "Portfolio","cash" => $_SESSION["cash"]]);

?>
