--
-- Begin Phase Script
-- Phase Number: 1

Lsys.DoFile("Script/input.lua")

g_nCamera = 0

function Lua_Init()
	Lsys.ShowState( 1 )
	Lsys.SetClearColor("0xFF006699")
	g_nFnt	= Lfont.New("HY¿±¼­L", 18, 1, 0, "0XFF00FF00", "0XFF333333", 1, 1)

	LxCam.SetEye  (g_nCamera,  20, 50, -100)
	LxCam.SetLook (g_nCamera,  20,  20, 40)
	LxCam.SetUp   (g_nCamera,   0,   1,  0)

	LxCam.SetBasis	 (g_nCamera, 20, 50, -100)
	LxCam.SetEpsilonY(g_nCamera, 0)
	LxCam.SetGap	 (g_nCamera, 600)
	LxCam.SetType	 (g_nCamera, 1)	-- 1ÀÎÄª Ä«¸Þ¶ó·Î ÀüÈ¯(2ÀÌ¸é 3ÀÎÄª)


	-- Map Load
	LxMap.New("Map/abd.bot", "Map/TblMdl.dat")


	-- Create Object: Need Name, ID
	g_nObj1 = LxObj.New("MyName", 123)
	LxObj.SetAttrib(g_nObj1, "Basic Model"	, "Model/etc/1011_1859.asb", "Model/etc/")

	-- Setup Attribute Object
	LxObj.SetAttrib(g_nObj1, "Position"		, 10, 0, 20)
	LxObj.SetAttrib(g_nObj1, "Camera"		, g_nCamera)
	LxObj.SetAttrib(g_nObj1, "Filed"		, 1)
	LxObj.Query(g_nObj1, "Setup Height"		)




	g_nObj2 = LxObj.New("AnOther", 124)
	LxObj.SetAttrib(g_nObj2, "Basic Model"	, "Model/etc/1011_1859.asb", "Model/etc/")
	LxObj.SetAttrib(g_nObj2, "Position"		, 40, 0, 50)
	LxObj.SetAttrib(g_nObj2, "Camera"		, g_nCamera)
	LxObj.SetAttrib(g_nObj2, "Filed"		, 1)
	LxObj.Query(g_nObj2, "Setup Height"		)

	return 0
end


function Lua_Destroy()
	return 0
end


function Lua_FrameMove()
	UpdateInput()

	-- Camera Update and, View And Projection Matrix Application
	LxCam.FrameMove()


	-- Map Update
	LxMap.FrameMove()

	-- Object Update
	LxObj.FrameMove(g_nObj1)
	LxObj.FrameMove(g_nObj2)

	return 0
end


function Lua_Render()
	-- View And Projection Matrix Application
	LxCam.SetTransformView(g_nCamera)
	LxCam.SetTransformProj(g_nCamera)

	-- Simple Polygon Model Rendering
	LxUtil.Command("Render Grid")
	LxUtil.Command("Render Axis")

	-- Map Rendering
	LxMap.Render()

	-- Object Rendering
	LxObj.Render(g_nObj1)
	LxObj.Render(g_nObj2)

	-- Font Rendering
	Lfont.Draw(g_nFnt, "Start", 10, 30, "0xFFFFFFFF")

return 0
end
