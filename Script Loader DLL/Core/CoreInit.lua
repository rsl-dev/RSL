-- Called during script loader initialization to set up all the global tables and functions.
-- I try to put as much intialization as possible in lua files, but some needs to be done from the C++ side of things.

rsl = {}
rfg = require("rfg.Init")

