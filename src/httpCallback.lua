_msg_key_log = function(...)
    print(string.format(...))
end
function httpCallback()
	local input =  DataUtil:getDataInputUtil()
	if not input then return end -- 防止
	local msgKey = input:readByte() .. '_' .. input:readByte()
	_msg_key_log("接收到消息回调 -->  msgKey : "..msgKey)
	APUtils.EventDispatcher:getInstance():dispatch(msgKey,input)
	
end
--[[  test
	cclog("byte :" .. input:readByte())
	cclog("byte :" .. input:readByte())
	cclog("int :" .. input:readInt())
	cclog("str :" .. input:readString())
	cclog("long :" .. input:readLong())
	if input:readBool() then
		cclog("bool : true")
	else
		cclog("bool : false")
	end
--]]