<?php

	//configuration
    require("../includes/config.php");

    // A form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["username"]))
        {
            apologize("You must provide your username.");
        }
        else if (empty($_POST["password"]))
        {
            apologize("You must provide your password.");
        }
        else if (empty($_POST["confirmation"]))
        {
            apologize("You must confirm your password.");
        }
        else if ($_POST["confirmation"] !== $_POST["password"])
        {
            apologize("Password and it's confirmation doesn't match.");
        }
        
        // Fail-safe - check if the user already exists
        $r = query("SELECT * FROM users WHERE username = ?", $_POST["username"]);
        
        // if we found user, check password
        if (count($r) == 1)
        {
            apologize("Specified username already exists.");
        }
        else{   
          // Register the user
            if(query("INSERT INTO users(username, hash, cash) VALUES (?, ?, 10000.00)", $_POST["username"], crypt($_POST["password"])) === false)
            {
                apologize("Could not register user.");
            }
            else
            {
                // Remember the session and redirect
                $rows = query("SELECT LAST_INSERT_ID() AS id");
                
                if (count($rows) == 1)
                {
                    $id = $rows[0]["id"];
                    
                    $_SESSION["id"] = $id;
                    redirect("/");
                }
            }
            
          }  
           
    }
    else
    {
        // Else render form
        render("register_form.php", ["title" => "Register"]);
    }
    
?>
