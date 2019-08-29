var Shopper = require('./Shopper');
var InventoryItem = require('./InventoryItem');

var alex = new Shopper('Alex', 100);

var walkman = new InventoryItem("Walkman", 29.99);
var necklace = new InventoryItem("Necklace", 9.99);

alex.purchase(necklace);
alex.purchase(walkman);

alex.printStatus();
