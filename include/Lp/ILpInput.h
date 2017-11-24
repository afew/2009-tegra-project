// Interface for the ILpInput class.
//
////////////////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif


#ifndef _ILpInput_H_
#define _ILpInput_H_


// Not defined Virtual Keys. So U'll make it.

// - on main keyboard
#define VK_MINUS		0xBD
#define VK_EQUALS		0xBB
#define VK_BACKSLASH	0xDC

#define VK_LBRACKET		0xDB
#define VK_RBRACKET		0xDD

#define VK_SEMICOLON	0xBA
#define VK_APOSTROPHE	0xDE

#define VK_COMMA		0xBC

// . on main keyboard
#define VK_PERIOD		0xBE
#define VK_SLASH		0xBF

#define VK_0			0x30
#define VK_1			0x31
#define VK_2			0x32
#define VK_3			0x33
#define VK_4			0x34
#define VK_5			0x35
#define VK_6			0x36
#define VK_7			0x37
#define VK_8			0x38
#define VK_9			0x39

#define VK_A			0x41
#define VK_B			0x42
#define VK_C			0x43
#define VK_D			0x44
#define VK_E			0x45
#define VK_F			0x46
#define VK_G			0x47

#define VK_H			0x48
#define VK_I			0x49
#define VK_J			0x4A
#define VK_K			0x4B
#define VK_L			0x4C
#define VK_M			0x4D
#define VK_N			0x4E

#define VK_O			0x4F
#define VK_P			0x50
#define VK_Q			0x51
#define VK_R			0x52
#define VK_S			0x53
#define VK_T			0x54
#define VK_U			0x55
#define VK_V			0x56
#define VK_W			0x57
#define VK_X			0x58
#define VK_Y			0x59
#define VK_Z			0x5A




enum EDirectInput
{
	DDIK_ESCAPE          = 0x01,
	DDIK_1               = 0x02,
	DDIK_2               = 0x03,
	DDIK_3               = 0x04,
	DDIK_4               = 0x05,
	DDIK_5               = 0x06,
	DDIK_6               = 0x07,
	DDIK_7               = 0x08,
	DDIK_8               = 0x09,
	DDIK_9               = 0x0A,
	DDIK_0               = 0x0B,
	DDIK_MINUS           = 0x0C,   /* - on main keyboard */
	DDIK_EQUALS          = 0x0D,
	DDIK_BACK            = 0x0E,   /* backspace */
	DDIK_TAB             = 0x0F,
	DDIK_Q               = 0x10,
	DDIK_W               = 0x11,
	DDIK_E               = 0x12,
	DDIK_R               = 0x13,
	DDIK_T               = 0x14,
	DDIK_Y               = 0x15,
	DDIK_U               = 0x16,
	DDIK_I               = 0x17,
	DDIK_O               = 0x18,
	DDIK_P               = 0x19,
	DDIK_LBRACKET        = 0x1A,
	DDIK_RBRACKET        = 0x1B,
	DDIK_RETURN          = 0x1C,    /* Enter on main keyboard */
	DDIK_LCONTROL        = 0x1D,
	DDIK_A               = 0x1E,
	DDIK_S               = 0x1F,
	DDIK_D               = 0x20,
	DDIK_F               = 0x21,
	DDIK_G               = 0x22,
	DDIK_H               = 0x23,
	DDIK_J               = 0x24,
	DDIK_K               = 0x25,
	DDIK_L               = 0x26,
	DDIK_SEMICOLON       = 0x27,
	DDIK_APOSTROPHE      = 0x28,
	DDIK_GRAVE           = 0x29,    /* accent grave */
	DDIK_LSHIFT          = 0x2A,
	DDIK_BACKSLASH       = 0x2B,
	DDIK_Z               = 0x2C,
	DDIK_X               = 0x2D,
	DDIK_C               = 0x2E,
	DDIK_V               = 0x2F,
	DDIK_B               = 0x30,
	DDIK_N               = 0x31,
	DDIK_M               = 0x32,
	DDIK_COMMA           = 0x33,
	DDIK_PERIOD          = 0x34,    /* . on main keyboard */
	DDIK_SLASH           = 0x35,    /* / on main keyboard */
	DDIK_RSHIFT          = 0x36,
	DDIK_MULTIPLY        = 0x37,    /* * on numeric keypad */
	DDIK_LMENU           = 0x38,    /* left Alt */
	DDIK_SPACE           = 0x39,
	DDIK_CAPITAL         = 0x3A,
	DDIK_F1              = 0x3B,
	DDIK_F2              = 0x3C,
	DDIK_F3              = 0x3D,
	DDIK_F4              = 0x3E,
	DDIK_F5              = 0x3F,
	DDIK_F6              = 0x40,
	DDIK_F7              = 0x41,
	DDIK_F8              = 0x42,
	DDIK_F9              = 0x43,
	DDIK_F10             = 0x44,
	DDIK_NUMLOCK         = 0x45,
	DDIK_SCROLL          = 0x46,    /* Scroll Lock */
	DDIK_NUMPAD7         = 0x47,
	DDIK_NUMPAD8         = 0x48,
	DDIK_NUMPAD9         = 0x49,
	DDIK_SUBTRACT        = 0x4A,    /* - on numeric keypad */
	DDIK_NUMPAD4         = 0x4B,
	DDIK_NUMPAD5         = 0x4C,
	DDIK_NUMPAD6         = 0x4D,
	DDIK_ADD             = 0x4E,    /* + on numeric keypad */
	DDIK_NUMPAD1         = 0x4F,
	DDIK_NUMPAD2         = 0x50,
	DDIK_NUMPAD3         = 0x51,
	DDIK_NUMPAD0         = 0x52,
	DDIK_DECIMAL         = 0x53,    /* . on numeric keypad */
	DDIK_OEM_102         = 0x56,    /* <> or \| on RT 102-key keyboard (Non-U.S.) */
	DDIK_F11             = 0x57,
	DDIK_F12             = 0x58,
	DDIK_F13             = 0x64,    /*                     (NEC PC98) */
	DDIK_F14             = 0x65,    /*                     (NEC PC98) */
	DDIK_F15             = 0x66,    /*                     (NEC PC98) */
	DDIK_KANA            = 0x70,    /* (Japanese keyboard)            */
	DDIK_ABNT_C1         = 0x73,    /* /? on Brazilian keyboard */
	DDIK_CONVERT         = 0x79,    /* (Japanese keyboard)            */
	DDIK_NOCONVERT       = 0x7B,    /* (Japanese keyboard)            */
	DDIK_YEN             = 0x7D,    /* (Japanese keyboard)            */
	DDIK_ABNT_C2         = 0x7E,    /* Numpad . on Brazilian keyboard */
	DDIK_NUMPADEQUALS    = 0x8D,    /* = on numeric keypad (NEC PC98) */
	DDIK_PREVTRACK       = 0x90,    /* Previous Track (DDIK_CIRCUMFLEX on Japanese keyboard) */
	DDIK_AT              = 0x91,    /*                     (NEC PC98) */
	DDIK_COLON           = 0x92,    /*                     (NEC PC98) */
	DDIK_UNDERLINE       = 0x93,    /*                     (NEC PC98) */
	DDIK_KANJI           = 0x94,    /* (Japanese keyboard)            */
	DDIK_STOP            = 0x95,    /*                     (NEC PC98) */
	DDIK_AX              = 0x96,    /*                     (Japan AX) */
	DDIK_UNLABELED       = 0x97,    /*                        (J3100) */
	DDIK_NEXTTRACK       = 0x99,    /* Next Track */
	DDIK_NUMPADENTER     = 0x9C,    /* Enter on numeric keypad */
	DDIK_RCONTROL        = 0x9D,
	DDIK_MUTE            = 0xA0,    /* Mute */
	DDIK_CALCULATOR      = 0xA1,    /* Calculator */
	DDIK_PLAYPAUSE       = 0xA2,    /* Play / Pause */
	DDIK_MEDIASTOP       = 0xA4,    /* Media Stop */
	DDIK_VOLUMEDOWN      = 0xAE,    /* Volume - */
	DDIK_VOLUMEUP        = 0xB0,    /* Volume + */
	DDIK_WEBHOME         = 0xB2,    /* Web home */
	DDIK_NUMPADCOMMA     = 0xB3,    /* , on numeric keypad (NEC PC98) */
	DDIK_DIVIDE          = 0xB5,    /* / on numeric keypad */
	DDIK_SYSRQ           = 0xB7,
	DDIK_RMENU           = 0xB8,    /* right Alt */
	DDIK_PAUSE           = 0xC5,    /* Pause */
	DDIK_HOME            = 0xC7,    /* Home on arrow keypad */
	DDIK_UP              = 0xC8,    /* UpArrow on arrow keypad */
	DDIK_PRIOR           = 0xC9,    /* PgUp on arrow keypad */
	DDIK_LEFT            = 0xCB,    /* LeftArrow on arrow keypad */
	DDIK_RIGHT           = 0xCD,    /* RightArrow on arrow keypad */
	DDIK_END             = 0xCF,    /* End on arrow keypad */
	DDIK_DOWN            = 0xD0,    /* DownArrow on arrow keypad */
	DDIK_NEXT            = 0xD1,    /* PgDn on arrow keypad */
	DDIK_INSERT          = 0xD2,    /* Insert on arrow keypad */
	DDIK_DELETE          = 0xD3,    /* Delete on arrow keypad */
	DDIK_LWIN            = 0xDB,    /* Left Windows key */
	DDIK_RWIN            = 0xDC,    /* Right Windows key */
	DDIK_APPS            = 0xDD,    /* AppMenu key */
	DDIK_POWER           = 0xDE,    /* System Power */
	DDIK_SLEEP           = 0xDF,    /* System Sleep */
	DDIK_WAKE            = 0xE3,    /* System Wake */
	DDIK_WEBSEARCH       = 0xE5,    /* Web Search */
	DDIK_WEBFAVORITES    = 0xE6,    /* Web Favorites */
	DDIK_WEBREFRESH      = 0xE7,    /* Web Refresh */
	DDIK_WEBSTOP         = 0xE8,    /* Web Stop */
	DDIK_WEBFORWARD      = 0xE9,    /* Web Forward */
	DDIK_WEBBACK         = 0xEA,    /* Web Back */
	DDIK_MYCOMPUTER      = 0xEB,    /* My Computer */
	DDIK_MAIL            = 0xEC,    /* Mail */
	DDIK_MEDIASELECT     = 0xED,    /* Media Select */
	
	DDIK_BACKSPACE       = DDIK_BACK    ,    /* backspace */
	DDIK_NUMPADSTAR      = DDIK_MULTIPLY,    /* * on numeric keypad */
	DDIK_LALT            = DDIK_LMENU   ,    /* left Alt */
	DDIK_CAPSLOCK        = DDIK_CAPITAL ,    /* CapsLock */
	DDIK_NUMPADMINUS     = DDIK_SUBTRACT,    /* - on numeric keypad */
	DDIK_NUMPADPLUS      = DDIK_ADD     ,    /* + on numeric keypad */
	DDIK_NUMPADPERIOD    = DDIK_DECIMAL ,    /* . on numeric keypad */
	DDIK_NUMPADSLASH     = DDIK_DIVIDE  ,    /* / on numeric keypad */
	DDIK_RALT            = DDIK_RMENU   ,    /* right Alt */
	DDIK_UPARROW         = DDIK_UP      ,    /* UpArrow on arrow keypad */
	DDIK_PGUP            = DDIK_PRIOR   ,    /* PgUp on arrow keypad */
	DDIK_LEFTARROW       = DDIK_LEFT    ,    /* LeftArrow on arrow keypad */
	DDIK_RIGHTARROW      = DDIK_RIGHT   ,    /* RightArrow on arrow keypad */
	DDIK_DOWNARROW       = DDIK_DOWN    ,    /* DownArrow on arrow keypad */
	DDIK_PGDN            = DDIK_NEXT    ,    /* PgDn on arrow keypad */
};






#ifdef USE_DIRECT_INPUT8

#define LNK_ESCAPE			DDIK_ESCAPE
#define LNK_1				DDIK_1
#define LNK_2				DDIK_2
#define LNK_3				DDIK_3
#define LNK_4				DDIK_4
#define LNK_5				DDIK_5
#define LNK_6				DDIK_6
#define LNK_7				DDIK_7
#define LNK_8				DDIK_8
#define LNK_9				DDIK_9
#define LNK_0				DDIK_0
#define LNK_MINUS			DDIK_MINUS
#define LNK_EQUALS			DDIK_EQUALS
#define LNK_BACK			DDIK_BACK
#define LNK_TAB				DDIK_TAB
#define LNK_Q				DDIK_Q
#define LNK_W				DDIK_W
#define LNK_E				DDIK_E
#define LNK_R				DDIK_R
#define LNK_T				DDIK_T
#define LNK_Y				DDIK_Y
#define LNK_U				DDIK_U
#define LNK_I				DDIK_I
#define LNK_O				DDIK_O
#define LNK_P				DDIK_P
#define LNK_LBRACKET		DDIK_LBRACKET
#define LNK_RBRACKET		DDIK_RBRACKET
#define LNK_RETURN			DDIK_RETURN
#define LNK_LCONTROL		DDIK_LCONTROL
#define LNK_A				DDIK_A
#define LNK_S				DDIK_S
#define LNK_D				DDIK_D
#define LNK_F				DDIK_F
#define LNK_G				DDIK_G
#define LNK_H				DDIK_H
#define LNK_J				DDIK_J
#define LNK_K				DDIK_K
#define LNK_L				DDIK_L
#define LNK_SEMICOLON		DDIK_SEMICOLON
#define LNK_APOSTROPHE		DDIK_APOSTROPHE
#define LNK_GRAVE			DDIK_GRAVE
#define LNK_LSHIFT			DDIK_LSHIFT
#define LNK_BACKSLASH		DDIK_BACKSLASH
#define LNK_Z				DDIK_Z
#define LNK_X				DDIK_X
#define LNK_C				DDIK_C
#define LNK_V				DDIK_V
#define LNK_B				DDIK_B
#define LNK_N				DDIK_N
#define LNK_M				DDIK_M
#define LNK_COMMA			DDIK_COMMA
#define LNK_PERIOD			DDIK_PERIOD
#define LNK_SLASH			DDIK_SLASH
#define LNK_RSHIFT			DDIK_RSHIFT
#define LNK_MULTIPLY		DDIK_MULTIPLY
#define LNK_LMENU			DDIK_LMENU
#define LNK_SPACE			DDIK_SPACE
#define LNK_CAPITAL			DDIK_CAPITAL
#define LNK_F1				DDIK_F1
#define LNK_F2				DDIK_F2
#define LNK_F3				DDIK_F3
#define LNK_F4				DDIK_F4
#define LNK_F5				DDIK_F5
#define LNK_F6				DDIK_F6
#define LNK_F7				DDIK_F7
#define LNK_F8				DDIK_F8
#define LNK_F9				DDIK_F9
#define LNK_F10				DDIK_F10
#define LNK_NUMLOCK			DDIK_NUMLOCK
#define LNK_SCROLL			DDIK_SCROLL
#define LNK_NUMPAD7			DDIK_NUMPAD7
#define LNK_NUMPAD8			DDIK_NUMPAD8
#define LNK_NUMPAD9			DDIK_NUMPAD9
#define LNK_SUBTRACT		DDIK_SUBTRACT
#define LNK_NUMPAD4			DDIK_NUMPAD4
#define LNK_NUMPAD5			DDIK_NUMPAD5
#define LNK_NUMPAD6			DDIK_NUMPAD6
#define LNK_ADD				DDIK_ADD
#define LNK_NUMPAD1			DDIK_NUMPAD1
#define LNK_NUMPAD2			DDIK_NUMPAD2
#define LNK_NUMPAD3			DDIK_NUMPAD3
#define LNK_NUMPAD0			DDIK_NUMPAD0
#define LNK_DECIMAL			DDIK_DECIMAL
#define LNK_OEM_102			DDIK_OEM_102
#define LNK_F11				DDIK_F11
#define LNK_F12				DDIK_F12
#define LNK_F13				DDIK_F13
#define LNK_F14				DDIK_F14
#define LNK_F15				DDIK_F15
#define LNK_KANA			DDIK_KANA
#define LNK_ABNT_C1			DDIK_ABNT_C1
#define LNK_CONVERT			DDIK_CONVERT
#define LNK_NOCONVERT		DDIK_NOCONVERT
#define LNK_YEN				DDIK_YEN
#define LNK_ABNT_C2			DDIK_ABNT_C2
#define LNK_NUMPADEQUALS    DDIK_NUMPADEQUALS
#define LNK_PREVTRACK		DDIK_PREVTRACK
#define LNK_AT				DDIK_AT
#define LNK_COLON			DDIK_COLON
#define LNK_UNDERLINE		DDIK_UNDERLINE
#define LNK_KANJI			DDIK_KANJI
#define LNK_STOP			DDIK_STOP
#define LNK_AX				DDIK_AX
#define LNK_UNLABELED		DDIK_UNLABELED
#define LNK_NEXTTRACK		DDIK_NEXTTRACK
#define LNK_NUMPADENTER		DDIK_NUMPADENTER
#define LNK_RCONTROL		DDIK_RCONTROL
#define LNK_MUTE			DDIK_MUTE
#define LNK_CALCULATOR		DDIK_CALCULATOR
#define LNK_PLAYPAUSE		DDIK_PLAYPAUSE
#define LNK_MEDIASTOP		DDIK_MEDIASTOP
#define LNK_VOLUMEDOWN		DDIK_VOLUMEDOWN
#define LNK_VOLUMEUP		DDIK_VOLUMEUP
#define LNK_WEBHOME			DDIK_WEBHOME
#define LNK_NUMPADCOMMA		DDIK_NUMPADCOMMA
#define LNK_DIVIDE			DDIK_DIVIDE
#define LNK_SYSRQ			DDIK_SYSRQ
#define LNK_RMENU			DDIK_RMENU
#define LNK_PAUSE			DDIK_PAUSE
#define LNK_HOME			DDIK_HOME
#define LNK_UP				DDIK_UP
#define LNK_PRIOR			DDIK_PRIOR
#define LNK_LEFT			DDIK_LEFT
#define LNK_RIGHT			DDIK_RIGHT
#define LNK_END				DDIK_END
#define LNK_DOWN			DDIK_DOWN
#define LNK_NEXT			DDIK_NEXT
#define LNK_INSERT			DDIK_INSERT
#define LNK_DELETE			DDIK_DELETE
#define LNK_LWIN			DDIK_LWIN
#define LNK_RWIN			DDIK_RWIN
#define LNK_APPS			DDIK_APPS
#define LNK_POWER			DDIK_POWER
#define LNK_SLEEP			DDIK_SLEEP
#define LNK_WAKE			DDIK_WAKE
#define LNK_WEBSEARCH		DDIK_WEBSEARCH
#define LNK_WEBFAVORITES	DDIK_WEBFAVORITES
#define LNK_WEBREFRESH		DDIK_WEBREFRESH
#define LNK_WEBSTOP			DDIK_WEBSTOP
#define LNK_WEBFORWARD		DDIK_WEBFORWARD
#define LNK_WEBBACK			DDIK_WEBBACK
#define LNK_MYCOMPUTER		DDIK_MYCOMPUTER
#define LNK_MAIL			DDIK_MAIL
#define LNK_MEDIASELECT		DDIK_MEDIASELECT

#define LNK_BACKSPACE		DDIK_BACKSPACE
#define LNK_NUMPADSTAR		DDIK_NUMPADSTAR
#define LNK_LALT			DDIK_LALT
#define LNK_CAPSLOCK		DDIK_CAPSLOCK
#define LNK_NUMPADMINUS		DDIK_NUMPADMINUS
#define LNK_NUMPADPLUS		DDIK_NUMPADPLUS
#define LNK_NUMPADPERIOD    DDIK_NUMPADPERIOD
#define LNK_NUMPADSLASH		DDIK_NUMPADSLASH
#define LNK_RALT			DDIK_RALT
#define LNK_UPARROW			DDIK_UPARROW
#define LNK_PGUP			DDIK_PGUP
#define LNK_LEFTARROW		DDIK_LEFTARROW
#define LNK_RIGHTARROW		DDIK_RIGHTARROW
#define LNK_DOWNARROW		DDIK_DOWNARROW
#define LNK_PGDN			DDIK_PGDN
#define LNK_CIRCUMFLEX		DDIK_CIRCUMFLEX

#else

#define LNK_LBUTTON			VK_LBUTTON
#define LNK_RBUTTON			VK_RBUTTON
#define LNK_CANCEL			VK_CANCEL
#define LNK_MBUTTON			VK_MBUTTON

#define LNK_BACK			VK_BACK
#define LNK_TAB				VK_TAB

#define LNK_CLEAR			VK_CLEAR
#define LNK_RETURN			VK_RETURN

#define LNK_SHIFT			VK_SHIFT
#define LNK_CONTROL			VK_CONTROL
#define LNK_MENU			VK_MENU
#define LNK_PAUSE			VK_PAUSE
#define LNK_CAPITAL			VK_CAPITAL

#define LNK_KANA			VK_KANA
#define LNK_HANGEUL			VK_HANGEUL
#define LNK_HANGUL			VK_HANGUL
#define LNK_JUNJA			VK_JUNJA
#define LNK_FINAL			VK_FINAL
#define LNK_HANJA			VK_HANJA
#define LNK_KANJI			VK_KANJI

#define LNK_ESCAPE			VK_ESCAPE

#define LNK_CONVERT			VK_CONVERT
#define LNK_NONCONVERT		VK_NONCONVERT
#define LNK_ACCEPT			VK_ACCEPT
#define LNK_MODECHANGE		VK_MODECHANGE

#define LNK_SPACE			VK_SPACE
#define LNK_PRIOR			VK_PRIOR
#define LNK_NEXT			VK_NEXT
#define LNK_END				VK_END
#define LNK_HOME			VK_HOME
#define LNK_LEFT			VK_LEFT
#define LNK_UP				VK_UP
#define LNK_RIGHT			VK_RIGHT
#define LNK_DOWN			VK_DOWN
#define LNK_SELECT			VK_SELECT
#define LNK_PRINT			VK_PRINT
#define LNK_EXECUTE			VK_EXECUTE
#define LNK_SNAPSHOT		VK_SNAPSHOT
#define LNK_INSERT			VK_INSERT
#define LNK_DELETE			VK_DELETE
#define LNK_HELP			VK_HELP

#define LNK_LWIN			VK_LWIN
#define LNK_RWIN			VK_RWIN
#define LNK_APPS			VK_APPS

#define LNK_NUMPAD0			VK_NUMPAD0
#define LNK_NUMPAD1			VK_NUMPAD1
#define LNK_NUMPAD2			VK_NUMPAD2
#define LNK_NUMPAD3			VK_NUMPAD3
#define LNK_NUMPAD4			VK_NUMPAD4
#define LNK_NUMPAD5			VK_NUMPAD5
#define LNK_NUMPAD6			VK_NUMPAD6
#define LNK_NUMPAD7			VK_NUMPAD7
#define LNK_NUMPAD8			VK_NUMPAD8
#define LNK_NUMPAD9			VK_NUMPAD9
#define LNK_MULTIPLY		VK_MULTIPLY
#define LNK_ADD				VK_ADD
#define LNK_SEPARATOR		VK_SEPARATOR
#define LNK_SUBTRACT		VK_SUBTRACT
#define LNK_DECIMAL			VK_DECIMAL
#define LNK_DIVIDE			VK_DIVIDE
#define LNK_F1				VK_F1
#define LNK_F2				VK_F2
#define LNK_F3				VK_F3
#define LNK_F4				VK_F4
#define LNK_F5				VK_F5
#define LNK_F6				VK_F6
#define LNK_F7				VK_F7
#define LNK_F8				VK_F8
#define LNK_F9				VK_F9
#define LNK_F10				VK_F10
#define LNK_F11				VK_F11
#define LNK_F12				VK_F12
#define LNK_F13				VK_F13
#define LNK_F14				VK_F14
#define LNK_F15				VK_F15
#define LNK_F16				VK_F16
#define LNK_F17				VK_F17
#define LNK_F18				VK_F18
#define LNK_F19				VK_F19
#define LNK_F20				VK_F20
#define LNK_F21				VK_F21
#define LNK_F22				VK_F22
#define LNK_F23				VK_F23
#define LNK_F24				VK_F24

#define LNK_NUMLOCK			VK_NUMLOCK
#define LNK_SCROLL			VK_SCROLL

#define LNK_LSHIFT			VK_LSHIFT
#define LNK_RSHIFT			VK_RSHIFT
#define LNK_LCONTROL		VK_LCONTROL
#define LNK_RCONTROL		VK_RCONTROL
#define LNK_LMENU			VK_LMENU
#define LNK_RMENU			VK_RMENU
#define LNK_LALT			VK_LMENU
#define LNK_RALT			VK_RMENU

#define LNK_PROCESSKEY		VK_PROCESSKEY

#define LNK_ATTN			VK_ATTN
#define LNK_CRSEL			VK_CRSEL
#define LNK_EXSEL			VK_EXSEL
#define LNK_EREOF			VK_EREOF
#define LNK_PLAY			VK_PLAY
#define LNK_ZOOM			VK_ZOOM
#define LNK_NONAME			VK_NONAME
#define LNK_PA1				VK_PA1
#define LNK_OEM_CLEAR		VK_OEM_CLEAR



#define LNK_MINUS			VK_MINUS
#define LNK_EQUALS			VK_EQUALS
#define LNK_BACKSLASH		VK_BACKSLASH
#define LNK_LBRACKET		VK_LBRACKET
#define LNK_RBRACKET		VK_RBRACKET
#define LNK_SEMICOLON		VK_SEMICOLON
#define LNK_APOSTROPHE		VK_APOSTROPHE
#define LNK_COMMA			VK_COMMA
#define LNK_PERIOD			VK_PERIOD
#define LNK_SLASH			VK_SLASH
#define LNK_SYSRQ			VK_SNAPSHOT
#define LNK_GRAVE			VK_SELECT


#define LNK_0				VK_0
#define LNK_1				VK_1
#define LNK_2				VK_2
#define LNK_3				VK_3
#define LNK_4				VK_4
#define LNK_5				VK_5
#define LNK_6				VK_6
#define LNK_7				VK_7
#define LNK_8				VK_8
#define LNK_9				VK_9

#define LNK_A				VK_A
#define LNK_B				VK_B
#define LNK_C				VK_C
#define LNK_D				VK_D
#define LNK_E				VK_E
#define LNK_F				VK_F
#define LNK_G				VK_G
#define LNK_H				VK_H
#define LNK_I				VK_I
#define LNK_J				VK_J
#define LNK_K				VK_K
#define LNK_L				VK_L
#define LNK_M				VK_M
#define LNK_N				VK_N
#define LNK_O				VK_O
#define LNK_P				VK_P
#define LNK_Q				VK_Q
#define LNK_R				VK_R
#define LNK_S				VK_S
#define LNK_T				VK_T
#define LNK_U				VK_U
#define LNK_V				VK_V
#define LNK_W				VK_W
#define LNK_X				VK_X
#define LNK_Y				VK_Y
#define LNK_Z				VK_Z

#endif


#define LNK_BUTTONL			0
#define LNK_BUTTONR			1
#define LNK_BUTTONM			2

#define LNK_KEYNONE			0
#define LNK_KEYDOWN			1
#define LNK_KEYUP			2
#define LNK_KEYPRESS		3



#ifndef interface
#define interface struct
#endif


#ifndef LC_CLASS_DESTROYER
#define LC_CLASS_DESTROYER( CLASS_NAME )	\
virtual ~CLASS_NAME(){}
#endif


interface ILpInput
{
	LC_CLASS_DESTROYER(	ILpInput	);
	
	virtual INT		Create(void* p1=0, void* p2=0, void* p3=0, void* p4=0)=0;
	virtual void	Destroy()=0;

	virtual INT		FrameMove()=0;

	
	virtual INT		Query(char* sCmd, void* pData)=0;


	virtual BYTE*	GetKeyMap()	const=0;
	virtual BYTE*	GetBtnMap()	const=0;

	virtual BOOL	KeyDown(INT nKey)=0;
	virtual BOOL	KeyUp(INT nKey)=0;
	virtual BOOL	KeyPress(INT nKey)=0;
	virtual BOOL	KeyState(int nKey)=0;

	virtual BOOL	ButtonDown(INT nBtn)=0;
	virtual BOOL	ButtonUp(INT nBtn)=0;
	virtual BOOL	ButtonPress(INT nBtn)=0;
	virtual BOOL	ButtonState(int nBtn)=0;

	virtual FLOAT*	GetMousePos()=0;
	virtual FLOAT*	GetMouseDelta()=0;
	virtual BOOL	GetMouseMove()=0;

	virtual BOOL	IsInRect(INT left, INT top, INT right, INT bottom)=0;

	virtual INT		MsgProc(HWND,UINT,WPARAM,LPARAM)=0;
};


INT LpInput_Create(char* sCmd
				 , ILpInput** pData
				 , void* p1			// HWND
				 , void* p2=0		// No Use
				 , void* p3=0		// No Use
				 , void* p4=0		// No Use
				 );


#ifdef USE_LP_SDK_LIB

	#if defined(_DEBUG) || defined(DEBUG)
		#pragma comment(lib, "LpInput_.lib")
	#else
		#pragma comment(lib, "LpInput.lib")
	#endif

#endif


#endif

