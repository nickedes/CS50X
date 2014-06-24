<div>
    <ul class="nav nav-pills">
    <li><a href="quote.php">Quote</a></li>
    <li><a href="buy.php">Buy</a></li>
    <li><a href="sell.php">Sell</a></li>
    <li><a href="history.php">History</a></li>
    <li><a href="deposit.php">Deposit</a></li>
    <li><a href="preferences.php">Preferences</a></li>
    <li><a href="logout.php"><strong>Log Out</strong></a></li>
</ul>
</div>

   
	 <table>
		<?php

		    foreach ($positions as $position)
		    {
		        print("<tr>");
		        print("<td>" . $position["symbol"] . "</td>");
		        print("<td>" . $position["shares"] . "</td>");
		        print("<td>" . $position["price"] . "</td>");
		        print("</tr>");
		    }

		?>
	</table>

