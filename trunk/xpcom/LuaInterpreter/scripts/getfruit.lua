-- get the fruit from the list
-- and store it in an array (table)
-- or our "basket" if you will
local fruit = "apple,pear,banana,pineapple"
local basket = {}
local i = 1
for fruit in string.gmatch(fruit, "%w+") do
    basket[i] = fruit
    i = i + 1
end
-- I needs a nice, fruity drink...
return "What about a nice " ..  basket[3] .. " smoothie?"
