package.cpath = './build/Release/?.dll;' .. package.cpath 
local sleep = require('sleep')
for i=1,10 do
	sleep(1000)
	print(i)
end