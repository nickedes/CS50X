<?php
require_once("functions.php");

    /**
     * Logs a purchase of a position
     */
    function logBuy($symbol, $shares, $price)
    {
         // add the transaction to the transactions table
         query("INSERT INTO history (id, action, symbol, shares, price) VALUES(?, 'BUY', ?, ?, ?)", $_SESSION["id"], $symbol, $shares, $price);
    }

    /**
     * Logs a purchase of a position
     */
    function logSell($symbol, $shares, $price)
    {
         // add the transaction to the transactions table
         query("INSERT INTO history (id, transaction, symbol, shares, price) VALUES(?, 'SELL', ?, ?, ?)", $_SESSION["id"], $symbol, $shares, $price);
    }
?>
