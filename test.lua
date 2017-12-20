local sleep = require('sleep')

local start = os.clock()

for i=1,10 do
	sleep(1000)
	io.write(i, " ")
end
io.write("\n")

local duration = os.clock() - start
assert(duration >= 9 and duration <= 11, "script ran for unexpected duration: " .. duration .. " seconds (expected ~10)")