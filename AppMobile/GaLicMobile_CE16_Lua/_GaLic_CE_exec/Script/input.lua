-- File: script.lua
-- Owner: Shim
-- Date: 2006-03-10
-- Update:
-- LuaApp.exe File call script.lua. script.lua is main script file.

-- Reseverd Function.
-- Lua_Create()
-- Lua_Init()
-- Lua_Destroy()
-- Lua_FrameMove()
-- Lua_Render()



-- Mcl_ Functions.

-- Lsys.CreateWindow(position_x, position_y, "title", FullMode)			// Window Create		
-- Lsys.Release()														// Window Release
-- Lsys.Sleep( time_milli_sceond)										// Sleep
-- Lsys.ShowCursor(0:FALSE, 1:TRUE)										// Show cursor

-- Lin.KeyboardAll()													// keyboard All Key
-- Lin.KeyboardOne( ascii )												// keyboard One Key
-- Lin.MousePos()														// Mouse Position x, y, z
-- Lin.MouseEvnt()														// Mouse Event Left, Right and M Button

-- Lsys.SetWindowTitle("title")											// Window Title
-- Lsys.MessageBox("Message", "Title", option)							// Window Box

-- Lsys.GetScnSize()													// ȭ���� ũ�⸦ ��������
-- Lsys.GetWindowStyle()												
-- Lsys.SetWindowStyle( style)											// window Style
-- Lsys.ShowState( Show )												// State ���̱� Show value is 1 or 0
-- Lsys.ChangeMode()													// Full <--> Window
-- Lsys.SetClearColor( Color )											// ���ȭ�� Ŭ���� ������ Color is ARGB color
-- Lsys.GetClearColor()													// ���ȭ�� Ŭ���� ���� ��������

-- Ltex.New( "File_Name" )												// �̹��� ���� �ε� return texture index
-- Ltex.Release( index )												// �̹��� ���� ����
-- Ltex.Width( index )													// �̹��� ���� �ʺ�
-- Ltex.Height( index	)												// �̹��� ���� ����
-- Texture index, image region left, top, right, bottom
	-- screen position x, screen position y

-- Ltex.Draw( texture_index
--					, Image_left
--					, Image_top
--					, Image_right
--					, Image_bottom
--					, screen_position_x
--					, screen_position_y	)								// �̹��� �׸���

-- Lsmd.New( "File_Name")												// ���� ���� �ε� return sound index
-- Lsmd.Release( index )												// ���� ���� ����
-- Lsmd.Play( index )													// ���� �÷���
-- Lsmd.Stop( index )													// ���� Stop
-- Lsmd.Reset( index )													// ���� Reset

-- Lfnt.New("Font_Name", Height, Style:Thin,Normal,Bold, Italic?)		// ��Ʈ �ε� return font index
-- Lfnt.Release( index )												// ��Ʈ ����
-- Lfnt.Draw( index, "String", screen_position_x, screen_position_y, "color")

-- Mcl Utilities
-- Lsys.GetTime()															// return time value after program start
-- Lutil.Mod(v1, v2)														// Modulate return v1 % v2
-- Lutil.Rand(v1)															// Randdom return rand()%v1
-- Lutil.SetConsole(v1)														// Console window. For error or message
-- Lutil.SendConsole(v1)													// Send String to colsole
-- Lutil.CastInt(v1)														// Casting Integer

-- Mcl Ime
-- Lime.Enable(0, 1)														// 0: Enable, 1: Disable
-- Lime.IsEnable()															// Is Enable? return 0, 1
-- Lime.Str()																// GetString
-- Lime.StrBeam()															// Get String with Beam
-- Lime.StrStar()															// Get String with Star
-- Lime.Set()																// Ime Set: Active and It will be all clear
-- Lime.Reset()																// Ime Reset: Disable and It will be all clear


-- File: Input.lua
-- Owner: Heesung Oh, copy reft
-- Date: 2005-03-08
-- Update
-- Description: Keyboard and mouse control
-- g_Keyboard: Keyboard array. Index 1~256. it is matched ASCII.
-- g_Mouse: Mouse array. g_Mouse[1]: mouse position x, g_Mousep[2]: mouse position y, g_Mouse[3]: mouse z position
-- g_Mouse[4]: Left button down, g_Mouse[5]: Right Button down, g_Mouse[6]: M button down


g_Keyboard={}
g_Mouse ={}


function UpdateInput()

	for i=1, 256, 1 do
		g_Keyboard[i] = Lin.KeyboardOne(i)
	end

	-- Get mouse postion
	MouseX, MouseY, MouseZ = Lin.MousePos()

	-- Get mouse event
	MouseEvntL, MouseEvntR, MouseEvntM = Lin.MouseEvnt()

	g_Mouse[1] = MouseX
	g_Mouse[2] = MouseY
	g_Mouse[3] = MouseZ

	g_Mouse[4]=MouseEvntL
	g_Mouse[5]=MouseEvntR
	g_Mouse[6]=MouseEvntM
	
	return 0
end

