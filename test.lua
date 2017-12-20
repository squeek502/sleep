local sleep = require('sleep')

local start = os.time()

for i=1,10 do
  sleep(1000)
  io.write(i, " ")
  io.flush()
end
io.write("\n")

local duration = os.time() - start
assert(duration >= 9 and duration <= 11, "script ran for unexpected duration: " .. duration .. " seconds (expected ~10)")