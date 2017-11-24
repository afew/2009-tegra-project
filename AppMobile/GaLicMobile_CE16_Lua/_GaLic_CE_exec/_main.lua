
--
-- 초기 설정
-- Date: 2006-10-19

function Lua_Create()
	Lsys.ScriptFile( 1, "Script/gp1Start.lua")
	Lsys.ScriptFile( 2, "Script/gp3End.lua")


	Lsys.ConsoleSet(0)									-- Using Console window
	Lsys.SetClearColor("0xFF006699")
	Lsys.ShowCursor(1)									--윈도 마우스포인터를 가린다

	-- Window create. position x, position y, screen width, screen height, title, fullmode?...
	return Lsys.CreateWindow(0, 0, 800, 450, "GaLic Soft(®) Tegra App(v0.9)", 0)
end

