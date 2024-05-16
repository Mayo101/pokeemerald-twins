# 1 "data/maps/Route111/scripts.pory"

# 2 "data/maps/Route111/scripts.pory"
.set LOCALID_VICTOR, 1
# 3 "data/maps/Route111/scripts.pory"
.set LOCALID_VICTORIA, 2
# 4 "data/maps/Route111/scripts.pory"
.set LOCALID_VIVI, 3
# 5 "data/maps/Route111/scripts.pory"
.set LOCALID_VICKY, 4
# 6 "data/maps/Route111/scripts.pory"
.set LOCALID_ROCK_SMASH_MAN, 46
# 7 "data/maps/Route111/scripts.pory"

# 8 "data/maps/Route111/scripts.pory"
@ Note: LOCALID_ROUTE111_PLAYER_FALLING is a local id for this map used elsewhere. It's defined in event_objects.h
# 9 "data/maps/Route111/scripts.pory"

# 10 "data/maps/Route111/scripts.pory"
Route111_MapScripts::
# 11 "data/maps/Route111/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route111_OnLoad
# 12 "data/maps/Route111/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route111_OnTransition
# 13 "data/maps/Route111/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route111_OnWarp
# 14 "data/maps/Route111/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route111_OnFrame
# 15 "data/maps/Route111/scripts.pory"
	.byte 0
# 16 "data/maps/Route111/scripts.pory"

# 17 "data/maps/Route111/scripts.pory"
Route111_OnLoad:
# 18 "data/maps/Route111/scripts.pory"
	call_if_unset FLAG_REGI_DOORS_OPENED, Route111_EventScript_CloseDesertRuins
# 19 "data/maps/Route111/scripts.pory"
	call_if_eq VAR_MIRAGE_TOWER_STATE, 1, Route111_EventScript_ShowTemporaryMirageTower
# 20 "data/maps/Route111/scripts.pory"
	end
# 21 "data/maps/Route111/scripts.pory"

# 22 "data/maps/Route111/scripts.pory"
Route111_EventScript_CloseDesertRuins::
# 23 "data/maps/Route111/scripts.pory"
	setmetatile 29, 86, METATILE_General_RockWall_RockBase, TRUE
# 24 "data/maps/Route111/scripts.pory"
	setmetatile 29, 87, METATILE_General_RockWall_SandBase, TRUE
# 25 "data/maps/Route111/scripts.pory"
	return
# 26 "data/maps/Route111/scripts.pory"

# 27 "data/maps/Route111/scripts.pory"
@ Show Mirage Tower just prior to disintegration. Mirage Tower is otherwise handled by the map layout
# 28 "data/maps/Route111/scripts.pory"
Route111_EventScript_ShowTemporaryMirageTower::
# 29 "data/maps/Route111/scripts.pory"
	setmetatile 18, 53, METATILE_Mauville_MirageTower_Tile0, FALSE
# 30 "data/maps/Route111/scripts.pory"
	setmetatile 19, 53, METATILE_Mauville_MirageTower_Tile1, FALSE
# 31 "data/maps/Route111/scripts.pory"
	setmetatile 20, 53, METATILE_Mauville_MirageTower_Tile2, FALSE
# 32 "data/maps/Route111/scripts.pory"
	setmetatile 18, 54, METATILE_Mauville_MirageTower_Tile3, FALSE
# 33 "data/maps/Route111/scripts.pory"
	setmetatile 19, 54, METATILE_Mauville_MirageTower_Tile4, FALSE
# 34 "data/maps/Route111/scripts.pory"
	setmetatile 20, 54, METATILE_Mauville_MirageTower_Tile5, FALSE
# 35 "data/maps/Route111/scripts.pory"
	setmetatile 18, 55, METATILE_Mauville_MirageTower_Tile6, FALSE
# 36 "data/maps/Route111/scripts.pory"
	setmetatile 19, 55, METATILE_Mauville_MirageTower_Tile7, FALSE
# 37 "data/maps/Route111/scripts.pory"
	setmetatile 20, 55, METATILE_Mauville_MirageTower_Tile8, FALSE
# 38 "data/maps/Route111/scripts.pory"
	setmetatile 18, 56, METATILE_Mauville_MirageTower_Tile9, FALSE
# 39 "data/maps/Route111/scripts.pory"
	setmetatile 19, 56, METATILE_Mauville_MirageTower_TileA, FALSE
# 40 "data/maps/Route111/scripts.pory"
	setmetatile 20, 56, METATILE_Mauville_MirageTower_TileB, FALSE
# 41 "data/maps/Route111/scripts.pory"
	setmetatile 18, 57, METATILE_Mauville_MirageTower_TileC, FALSE
# 42 "data/maps/Route111/scripts.pory"
	setmetatile 19, 57, METATILE_Mauville_MirageTower_TileD, FALSE
# 43 "data/maps/Route111/scripts.pory"
	setmetatile 20, 57, METATILE_Mauville_MirageTower_TileE, FALSE
# 44 "data/maps/Route111/scripts.pory"
	setmetatile 18, 58, METATILE_Mauville_MirageTower_TileF, FALSE
# 45 "data/maps/Route111/scripts.pory"
	setmetatile 19, 58, METATILE_Mauville_MirageTower_Tile10, FALSE
# 46 "data/maps/Route111/scripts.pory"
	setmetatile 20, 58, METATILE_Mauville_MirageTower_Tile11, FALSE
# 47 "data/maps/Route111/scripts.pory"
	return
# 48 "data/maps/Route111/scripts.pory"

# 49 "data/maps/Route111/scripts.pory"
Route111_OnTransition:
# 50 "data/maps/Route111/scripts.pory"
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
# 51 "data/maps/Route111/scripts.pory"
	special SetMirageTowerVisibility
# 52 "data/maps/Route111/scripts.pory"
	call_if_unset FLAG_MIRAGE_TOWER_VISIBLE, Route111_EventScript_SetLayoutNoMirageTower
# 53 "data/maps/Route111/scripts.pory"
	call_if_eq VAR_MIRAGE_TOWER_STATE, 1, Route111_EventScript_SetFallingPlayerGfx
# 54 "data/maps/Route111/scripts.pory"
	call_if_eq VAR_MIRAGE_TOWER_STATE, 2, Route111_EventScript_SetMirageTowerGone
# 55 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CheckSetSandstorm
# 56 "data/maps/Route111/scripts.pory"
	call GabbyAndTy_EventScript_UpdateLocation
# 57 "data/maps/Route111/scripts.pory"
	goto_if_not_defeated TRAINER_VICKY, Route111_EventScript_SetWinstratesNotDefeated
# 58 "data/maps/Route111/scripts.pory"
	end
# 59 "data/maps/Route111/scripts.pory"

# 60 "data/maps/Route111/scripts.pory"
Route111_EventScript_SetFallingPlayerGfx::
# 61 "data/maps/Route111/scripts.pory"
	checkplayergender
# 62 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, Route111_EventScript_SetFallingPlayerGfxMale
# 63 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, Route111_EventScript_SetFallingPlayerGfxFemale
# 64 "data/maps/Route111/scripts.pory"
	return
# 65 "data/maps/Route111/scripts.pory"

# 66 "data/maps/Route111/scripts.pory"
Route111_EventScript_SetFallingPlayerGfxMale::
# 67 "data/maps/Route111/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 68 "data/maps/Route111/scripts.pory"
	return
# 69 "data/maps/Route111/scripts.pory"

# 70 "data/maps/Route111/scripts.pory"
Route111_EventScript_SetFallingPlayerGfxFemale::
# 71 "data/maps/Route111/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 72 "data/maps/Route111/scripts.pory"
	return
# 73 "data/maps/Route111/scripts.pory"

# 74 "data/maps/Route111/scripts.pory"
Route111_EventScript_CheckSetSandstorm::
# 75 "data/maps/Route111/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 76 "data/maps/Route111/scripts.pory"
	goto_if_lt VAR_TEMP_1, 34, Route111_EventScript_EndCheckSetSandstorm
# 77 "data/maps/Route111/scripts.pory"
	goto_if_gt VAR_TEMP_1, 107, Route111_EventScript_EndCheckSetSandstorm
# 78 "data/maps/Route111/scripts.pory"
	goto_if_gt VAR_TEMP_1, 72, Route111_EventScript_SetSandstorm
# 79 "data/maps/Route111/scripts.pory"
	goto_if_gt VAR_TEMP_0, 2000, Route111_EventScript_EndCheckSetSandstorm
# 80 "data/maps/Route111/scripts.pory"
	goto_if_lt VAR_TEMP_0, 8, Route111_EventScript_EndCheckSetSandstorm
# 81 "data/maps/Route111/scripts.pory"
Route111_EventScript_SetSandstorm::
# 82 "data/maps/Route111/scripts.pory"
	setweather WEATHER_SANDSTORM
# 83 "data/maps/Route111/scripts.pory"
	setvar VAR_ROUTE111_WILD_SET, 1
# 84 "data/maps/Route111/scripts.pory"
	return
# 85 "data/maps/Route111/scripts.pory"
Route111_EventScript_EndCheckSetSandstorm::
# 86 "data/maps/Route111/scripts.pory"
	setvar VAR_ROUTE111_WILD_SET, 0
# 87 "data/maps/Route111/scripts.pory"
	return
# 88 "data/maps/Route111/scripts.pory"

# 89 "data/maps/Route111/scripts.pory"
Route111_EventScript_SetWinstratesNotDefeated::
# 90 "data/maps/Route111/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_111_VICTOR_WINSTRATE
# 91 "data/maps/Route111/scripts.pory"
	setflag FLAG_HIDE_ROUTE_111_VICTORIA_WINSTRATE
# 92 "data/maps/Route111/scripts.pory"
	setflag FLAG_HIDE_ROUTE_111_VIVI_WINSTRATE
# 93 "data/maps/Route111/scripts.pory"
	setflag FLAG_HIDE_ROUTE_111_VICKY_WINSTRATE
# 94 "data/maps/Route111/scripts.pory"
	cleartrainerflag TRAINER_VICTOR
# 95 "data/maps/Route111/scripts.pory"
	cleartrainerflag TRAINER_VICTORIA
# 96 "data/maps/Route111/scripts.pory"
	cleartrainerflag TRAINER_VIVI
# 97 "data/maps/Route111/scripts.pory"
	end
# 98 "data/maps/Route111/scripts.pory"

# 99 "data/maps/Route111/scripts.pory"
Route111_EventScript_SetLayoutNoMirageTower::
# 100 "data/maps/Route111/scripts.pory"
	setmaplayoutindex LAYOUT_ROUTE111_NO_MIRAGE_TOWER
# 101 "data/maps/Route111/scripts.pory"
	return
# 102 "data/maps/Route111/scripts.pory"

# 103 "data/maps/Route111/scripts.pory"
Route111_EventScript_SetMirageTowerGone::
# 104 "data/maps/Route111/scripts.pory"
	setvar VAR_MIRAGE_TOWER_STATE, 3
# 105 "data/maps/Route111/scripts.pory"
	return
# 106 "data/maps/Route111/scripts.pory"

# 107 "data/maps/Route111/scripts.pory"
Route111_OnWarp:
# 108 "data/maps/Route111/scripts.pory"
	map_script_2 VAR_MIRAGE_TOWER_STATE, 1, Route111_EventScript_HidePlayerForMirageTower
# 109 "data/maps/Route111/scripts.pory"
	.2byte 0
# 110 "data/maps/Route111/scripts.pory"

# 111 "data/maps/Route111/scripts.pory"
Route111_EventScript_HidePlayerForMirageTower::
# 112 "data/maps/Route111/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_LITTLEROOT_TOWN
# 113 "data/maps/Route111/scripts.pory"
	end
# 114 "data/maps/Route111/scripts.pory"

# 115 "data/maps/Route111/scripts.pory"
Route111_OnFrame:
# 116 "data/maps/Route111/scripts.pory"
	map_script_2 VAR_MIRAGE_TOWER_STATE, 1, Route111_EventScript_MirageTowerDisappear
# 117 "data/maps/Route111/scripts.pory"
	.2byte 0
# 118 "data/maps/Route111/scripts.pory"

# 119 "data/maps/Route111/scripts.pory"
Route111_EventScript_MirageTowerDisappear::
# 120 "data/maps/Route111/scripts.pory"
	lockall
# 121 "data/maps/Route111/scripts.pory"
	special StartMirageTowerShake
# 122 "data/maps/Route111/scripts.pory"
	waitstate
# 123 "data/maps/Route111/scripts.pory"
	delay 24
# 124 "data/maps/Route111/scripts.pory"
	playse SE_FALL
# 125 "data/maps/Route111/scripts.pory"
	addobject LOCALID_ROUTE111_PLAYER_FALLING
# 126 "data/maps/Route111/scripts.pory"
	special StartPlayerDescendMirageTower
# 127 "data/maps/Route111/scripts.pory"
	waitstate
# 128 "data/maps/Route111/scripts.pory"
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_LITTLEROOT_TOWN
# 129 "data/maps/Route111/scripts.pory"
	removeobject LOCALID_ROUTE111_PLAYER_FALLING
# 130 "data/maps/Route111/scripts.pory"
	delay 16
# 131 "data/maps/Route111/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 132 "data/maps/Route111/scripts.pory"
	delay 16
# 133 "data/maps/Route111/scripts.pory"
	special StartMirageTowerDisintegration
# 134 "data/maps/Route111/scripts.pory"
	waitstate
# 135 "data/maps/Route111/scripts.pory"
	special StartMirageTowerFossilFallAndSink
# 136 "data/maps/Route111/scripts.pory"
	waitstate
# 137 "data/maps/Route111/scripts.pory"
	setvar VAR_MIRAGE_TOWER_STATE, 2
# 138 "data/maps/Route111/scripts.pory"
	clearflag FLAG_HIDE_DESERT_UNDERPASS_FOSSIL
# 139 "data/maps/Route111/scripts.pory"
	goto_if_set FLAG_CHOSE_CLAW_FOSSIL, Route111_EventScript_RootFossilDisappeared
# 140 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ClawFossilDisappeared, MSGBOX_DEFAULT
# 141 "data/maps/Route111/scripts.pory"
	releaseall
# 142 "data/maps/Route111/scripts.pory"
	end
# 143 "data/maps/Route111/scripts.pory"

# 144 "data/maps/Route111/scripts.pory"
Route111_EventScript_RootFossilDisappeared::
# 145 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_RootFossilDisappeared, MSGBOX_DEFAULT
# 146 "data/maps/Route111/scripts.pory"
	releaseall
# 147 "data/maps/Route111/scripts.pory"
	end
# 148 "data/maps/Route111/scripts.pory"

# 149 "data/maps/Route111/scripts.pory"
@ Unused
# 150 "data/maps/Route111/scripts.pory"
Route111_Movement_PlayerFall::
# 151 "data/maps/Route111/scripts.pory"
	lock_anim
# 152 "data/maps/Route111/scripts.pory"
	walk_fast_down
# 153 "data/maps/Route111/scripts.pory"
	walk_fast_down
# 154 "data/maps/Route111/scripts.pory"
	walk_fast_down
# 155 "data/maps/Route111/scripts.pory"
	walk_fast_down
# 156 "data/maps/Route111/scripts.pory"
	walk_fast_down
# 157 "data/maps/Route111/scripts.pory"
	walk_fast_down
# 158 "data/maps/Route111/scripts.pory"
	step_end
# 159 "data/maps/Route111/scripts.pory"

# 160 "data/maps/Route111/scripts.pory"
Route111_EventScript_Girl::
# 161 "data/maps/Route111/scripts.pory"
	lock
# 162 "data/maps/Route111/scripts.pory"
	faceplayer
# 163 "data/maps/Route111/scripts.pory"
	dotimebasedevents
# 164 "data/maps/Route111/scripts.pory"
	goto_if_set FLAG_DAILY_ROUTE_111_RECEIVED_BERRY, Route111_EventScript_ReceivedBerry
# 165 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WateredPlantsEveryDayTakeBerry, MSGBOX_DEFAULT
# 166 "data/maps/Route111/scripts.pory"
	giveitem ITEM_RAZZ_BERRY
# 167 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 168 "data/maps/Route111/scripts.pory"
	setflag FLAG_DAILY_ROUTE_111_RECEIVED_BERRY
# 169 "data/maps/Route111/scripts.pory"
	special GetPlayerBigGuyGirlString
# 170 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_GoingToTryToMakeDifferentColorBerries, MSGBOX_DEFAULT
# 171 "data/maps/Route111/scripts.pory"
	release
# 172 "data/maps/Route111/scripts.pory"
	end
# 173 "data/maps/Route111/scripts.pory"

# 174 "data/maps/Route111/scripts.pory"
Route111_EventScript_ReceivedBerry::
# 175 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WhatColorBerriesToLookForToday, MSGBOX_DEFAULT
# 176 "data/maps/Route111/scripts.pory"
	release
# 177 "data/maps/Route111/scripts.pory"
	end
# 178 "data/maps/Route111/scripts.pory"

# 179 "data/maps/Route111/scripts.pory"
@ Unused
# 180 "data/maps/Route111/scripts.pory"
Route111_EventScript_ViciousSandstormTriggerUp::
# 181 "data/maps/Route111/scripts.pory"
	lockall
# 182 "data/maps/Route111/scripts.pory"
	setvar VAR_0x8004, 0
# 183 "data/maps/Route111/scripts.pory"
	goto Route111_EventScript_ViciousSandstormTrigger
# 184 "data/maps/Route111/scripts.pory"
	end
# 185 "data/maps/Route111/scripts.pory"

# 186 "data/maps/Route111/scripts.pory"
Route111_EventScript_ViciousSandstormTriggerDown::
# 187 "data/maps/Route111/scripts.pory"
	lockall
# 188 "data/maps/Route111/scripts.pory"
	setvar VAR_0x8004, 1
# 189 "data/maps/Route111/scripts.pory"
	goto Route111_EventScript_ViciousSandstormTrigger
# 190 "data/maps/Route111/scripts.pory"
	end
# 191 "data/maps/Route111/scripts.pory"

# 192 "data/maps/Route111/scripts.pory"
Route111_EventScript_ViciousSandstormTriggerLeft::
# 193 "data/maps/Route111/scripts.pory"
	lockall
# 194 "data/maps/Route111/scripts.pory"
	setvar VAR_0x8004, 2
# 195 "data/maps/Route111/scripts.pory"
	goto Route111_EventScript_ViciousSandstormTrigger
# 196 "data/maps/Route111/scripts.pory"
	end
# 197 "data/maps/Route111/scripts.pory"

# 198 "data/maps/Route111/scripts.pory"
@ Unused
# 199 "data/maps/Route111/scripts.pory"
Route111_EventScript_ViciousSandstormTriggerRight::
# 200 "data/maps/Route111/scripts.pory"
	lockall
# 201 "data/maps/Route111/scripts.pory"
	setvar VAR_0x8004, 3
# 202 "data/maps/Route111/scripts.pory"
	goto Route111_EventScript_ViciousSandstormTrigger
# 203 "data/maps/Route111/scripts.pory"
	end
# 204 "data/maps/Route111/scripts.pory"

# 205 "data/maps/Route111/scripts.pory"
Route111_EventScript_ViciousSandstormTrigger::
# 206 "data/maps/Route111/scripts.pory"
	checkitem ITEM_GO_GOGGLES
# 207 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route111_EventScript_PreventRouteAccess
# 208 "data/maps/Route111/scripts.pory"
	setvar VAR_TEMP_3, 1
# 209 "data/maps/Route111/scripts.pory"
	releaseall
# 210 "data/maps/Route111/scripts.pory"
	end
# 211 "data/maps/Route111/scripts.pory"

# 212 "data/maps/Route111/scripts.pory"
Route111_EventScript_PreventRouteAccess::
# 213 "data/maps/Route111/scripts.pory"
	msgbox gText_SandstormIsVicious, MSGBOX_DEFAULT
# 214 "data/maps/Route111/scripts.pory"
	closemessage
# 215 "data/maps/Route111/scripts.pory"
	call_if_eq VAR_0x8004, 0, Route111_EventScript_PushUpFromRoute
# 216 "data/maps/Route111/scripts.pory"
	call_if_eq VAR_0x8004, 1, Route111_EventScript_PushDownFromRoute
# 217 "data/maps/Route111/scripts.pory"
	call_if_eq VAR_0x8004, 2, Route111_EventScript_PushLeftFromRoute
# 218 "data/maps/Route111/scripts.pory"
	call_if_eq VAR_0x8004, 3, Route111_EventScript_PushRightFromRoute
# 219 "data/maps/Route111/scripts.pory"
	releaseall
# 220 "data/maps/Route111/scripts.pory"
	end
# 221 "data/maps/Route111/scripts.pory"

# 222 "data/maps/Route111/scripts.pory"
Route111_EventScript_PushUpFromRoute::
# 223 "data/maps/Route111/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_PushUpFromRoute
# 224 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 225 "data/maps/Route111/scripts.pory"
	return
# 226 "data/maps/Route111/scripts.pory"

# 227 "data/maps/Route111/scripts.pory"
Route111_EventScript_PushDownFromRoute::
# 228 "data/maps/Route111/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_PushDownFromRoute
# 229 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 230 "data/maps/Route111/scripts.pory"
	return
# 231 "data/maps/Route111/scripts.pory"

# 232 "data/maps/Route111/scripts.pory"
Route111_EventScript_PushLeftFromRoute::
# 233 "data/maps/Route111/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_PushLeftFromRoute
# 234 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 235 "data/maps/Route111/scripts.pory"
	return
# 236 "data/maps/Route111/scripts.pory"

# 237 "data/maps/Route111/scripts.pory"
Route111_EventScript_PushRightFromRoute::
# 238 "data/maps/Route111/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_PushRightFromRoute
# 239 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 240 "data/maps/Route111/scripts.pory"
	return
# 241 "data/maps/Route111/scripts.pory"

# 242 "data/maps/Route111/scripts.pory"
Route111_Movement_PushUpFromRoute:
# 243 "data/maps/Route111/scripts.pory"
	walk_up
# 244 "data/maps/Route111/scripts.pory"
	step_end
# 245 "data/maps/Route111/scripts.pory"

# 246 "data/maps/Route111/scripts.pory"
Route111_Movement_PushDownFromRoute:
# 247 "data/maps/Route111/scripts.pory"
	walk_down
# 248 "data/maps/Route111/scripts.pory"
	step_end
# 249 "data/maps/Route111/scripts.pory"

# 250 "data/maps/Route111/scripts.pory"
Route111_Movement_PushLeftFromRoute:
# 251 "data/maps/Route111/scripts.pory"
	walk_left
# 252 "data/maps/Route111/scripts.pory"
	step_end
# 253 "data/maps/Route111/scripts.pory"

# 254 "data/maps/Route111/scripts.pory"
Route111_Movement_PushRightFromRoute:
# 255 "data/maps/Route111/scripts.pory"
	walk_right
# 256 "data/maps/Route111/scripts.pory"
	step_end
# 257 "data/maps/Route111/scripts.pory"

# 258 "data/maps/Route111/scripts.pory"
Route111_EventScript_SunTrigger::
# 259 "data/maps/Route111/scripts.pory"
	setweather WEATHER_SUNNY
# 260 "data/maps/Route111/scripts.pory"
	fadenewbgm MUS_ROUTE110
# 261 "data/maps/Route111/scripts.pory"
	doweather
# 262 "data/maps/Route111/scripts.pory"
	setvar VAR_TEMP_3, 0
# 263 "data/maps/Route111/scripts.pory"
	setvar VAR_ROUTE111_WILD_SET, 0
# 264 "data/maps/Route111/scripts.pory"
	end
# 265 "data/maps/Route111/scripts.pory"

# 266 "data/maps/Route111/scripts.pory"
Route111_EventScript_SandstormTrigger::
# 267 "data/maps/Route111/scripts.pory"
	setweather WEATHER_SANDSTORM
# 268 "data/maps/Route111/scripts.pory"
	fadenewbgm MUS_DESERT
# 269 "data/maps/Route111/scripts.pory"
	doweather
# 270 "data/maps/Route111/scripts.pory"
	setvar VAR_ROUTE111_WILD_SET, 1
# 271 "data/maps/Route111/scripts.pory"
	end
# 272 "data/maps/Route111/scripts.pory"

# 273 "data/maps/Route111/scripts.pory"
Route111_EventScript_Victor::
# 274 "data/maps/Route111/scripts.pory"
	lock
# 275 "data/maps/Route111/scripts.pory"
	faceplayer
# 276 "data/maps/Route111/scripts.pory"
	setflag FLAG_LANDMARK_WINSTRATE_FAMILY
# 277 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BattleOurFamily, MSGBOX_YESNO
# 278 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route111_EventScript_BattleWinstrates
# 279 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_IsThatSo, MSGBOX_DEFAULT
# 280 "data/maps/Route111/scripts.pory"
	release
# 281 "data/maps/Route111/scripts.pory"
	end
# 282 "data/maps/Route111/scripts.pory"

# 283 "data/maps/Route111/scripts.pory"
Route111_EventScript_BattleWinstrates::
# 284 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_VictorIntro, MSGBOX_DEFAULT
# 285 "data/maps/Route111/scripts.pory"
	trainerbattle_no_intro TRAINER_VICTOR, Route111_Text_VictorDefeat
# 286 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_VICTOR, Common_Movement_WalkInPlaceFasterUp
# 287 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 288 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 289 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_VictorPostBattle, MSGBOX_DEFAULT
# 290 "data/maps/Route111/scripts.pory"
	closemessage
# 291 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_VICTOR, Route111_Movement_WinstrateEnterHouse
# 292 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 293 "data/maps/Route111/scripts.pory"
	removeobject LOCALID_VICTOR
# 294 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 295 "data/maps/Route111/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_WaitForNextWinstrate
# 296 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 297 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 298 "data/maps/Route111/scripts.pory"
	addobject LOCALID_VICTORIA
# 299 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_VICTORIA, Route111_Movement_WinstrateExitHouse
# 300 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 301 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 302 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_VictoriaIntro, MSGBOX_DEFAULT
# 303 "data/maps/Route111/scripts.pory"
	trainerbattle_no_intro TRAINER_VICTORIA, Route111_Text_VictoriaDefeat
# 304 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_VICTORIA, Common_Movement_WalkInPlaceFasterUp
# 305 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 306 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 307 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_VictoriaPostBattle, MSGBOX_DEFAULT
# 308 "data/maps/Route111/scripts.pory"
	closemessage
# 309 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_VICTORIA, Route111_Movement_WinstrateEnterHouse
# 310 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 311 "data/maps/Route111/scripts.pory"
	removeobject LOCALID_VICTORIA
# 312 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 313 "data/maps/Route111/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_WaitForNextWinstrate
# 314 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 315 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 316 "data/maps/Route111/scripts.pory"
	addobject LOCALID_VIVI
# 317 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_VIVI, Route111_Movement_WinstrateExitHouse
# 318 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 319 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 320 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ViviIntro, MSGBOX_DEFAULT
# 321 "data/maps/Route111/scripts.pory"
	trainerbattle_no_intro TRAINER_VIVI, Route111_Text_ViviDefeat
# 322 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_VIVI, Common_Movement_WalkInPlaceFasterUp
# 323 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 324 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 325 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ViviPostBattle, MSGBOX_DEFAULT
# 326 "data/maps/Route111/scripts.pory"
	closemessage
# 327 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_VIVI, Route111_Movement_WinstrateEnterHouse
# 328 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 329 "data/maps/Route111/scripts.pory"
	removeobject LOCALID_VIVI
# 330 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 331 "data/maps/Route111/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_WaitForNextWinstrate
# 332 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 333 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 334 "data/maps/Route111/scripts.pory"
	addobject LOCALID_VICKY
# 335 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_VICKY, Route111_Movement_WinstrateExitHouse
# 336 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 337 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 338 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_VickyIntro, MSGBOX_DEFAULT
# 339 "data/maps/Route111/scripts.pory"
	trainerbattle_no_intro TRAINER_VICKY, Route111_Text_VickyDefeat
# 340 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_VickyPostBattle, MSGBOX_DEFAULT
# 341 "data/maps/Route111/scripts.pory"
	closemessage
# 342 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_VICKY, Common_Movement_WalkInPlaceFasterUp
# 343 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 344 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 345 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_VICKY, Route111_Movement_WinstrateEnterHouse
# 346 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 347 "data/maps/Route111/scripts.pory"
	removeobject LOCALID_VICKY
# 348 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 349 "data/maps/Route111/scripts.pory"
	release
# 350 "data/maps/Route111/scripts.pory"
	end
# 351 "data/maps/Route111/scripts.pory"

# 352 "data/maps/Route111/scripts.pory"
Route111_EventScript_OpenWinstrateDoor::
# 353 "data/maps/Route111/scripts.pory"
	opendoor 13, 113
# 354 "data/maps/Route111/scripts.pory"
	waitdooranim
# 355 "data/maps/Route111/scripts.pory"
	return
# 356 "data/maps/Route111/scripts.pory"

# 357 "data/maps/Route111/scripts.pory"
Route111_EventScript_CloseWinstrateDoor::
# 358 "data/maps/Route111/scripts.pory"
	closedoor 13, 113
# 359 "data/maps/Route111/scripts.pory"
	waitdooranim
# 360 "data/maps/Route111/scripts.pory"
	return
# 361 "data/maps/Route111/scripts.pory"

# 362 "data/maps/Route111/scripts.pory"
Route111_Movement_WinstrateEnterHouse:
# 363 "data/maps/Route111/scripts.pory"
	walk_in_place_faster_up
# 364 "data/maps/Route111/scripts.pory"
	walk_up
# 365 "data/maps/Route111/scripts.pory"
	step_end
# 366 "data/maps/Route111/scripts.pory"

# 367 "data/maps/Route111/scripts.pory"
Route111_Movement_WinstrateExitHouse:
# 368 "data/maps/Route111/scripts.pory"
	walk_down
# 369 "data/maps/Route111/scripts.pory"
	step_end
# 370 "data/maps/Route111/scripts.pory"

# 371 "data/maps/Route111/scripts.pory"
Route111_Movement_WaitForNextWinstrate:
# 372 "data/maps/Route111/scripts.pory"
	delay_16
# 373 "data/maps/Route111/scripts.pory"
	delay_16
# 374 "data/maps/Route111/scripts.pory"
	delay_16
# 375 "data/maps/Route111/scripts.pory"
	step_end
# 376 "data/maps/Route111/scripts.pory"

# 377 "data/maps/Route111/scripts.pory"
Route111_EventScript_RouteSignMauville::
# 378 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_RouteSignMauville, MSGBOX_SIGN
# 379 "data/maps/Route111/scripts.pory"
	end
# 380 "data/maps/Route111/scripts.pory"

# 381 "data/maps/Route111/scripts.pory"
Route111_EventScript_WinstrateHouseSign::
# 382 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WinstrateHouseSign, MSGBOX_SIGN
# 383 "data/maps/Route111/scripts.pory"
	end
# 384 "data/maps/Route111/scripts.pory"

# 385 "data/maps/Route111/scripts.pory"
Route111_EventScript_RouteSign112::
# 386 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_RouteSign112, MSGBOX_SIGN
# 387 "data/maps/Route111/scripts.pory"
	end
# 388 "data/maps/Route111/scripts.pory"

# 389 "data/maps/Route111/scripts.pory"
Route111_EventScript_RouteSign113::
# 390 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_RouteSign113, MSGBOX_SIGN
# 391 "data/maps/Route111/scripts.pory"
	end
# 392 "data/maps/Route111/scripts.pory"

# 393 "data/maps/Route111/scripts.pory"
Route111_EventScript_OldLadysRestStopSign::
# 394 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_OldLadysRestStopSign, MSGBOX_SIGN
# 395 "data/maps/Route111/scripts.pory"
	end
# 396 "data/maps/Route111/scripts.pory"

# 397 "data/maps/Route111/scripts.pory"
Route111_EventScript_TrainerTipsSpAtkSpDef::
# 398 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_TrainerTipsSpAtkSpDef, MSGBOX_SIGN
# 399 "data/maps/Route111/scripts.pory"
	end
# 400 "data/maps/Route111/scripts.pory"

# 401 "data/maps/Route111/scripts.pory"
Route111_EventScript_Man1::
# 402 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ToughToKeepWinningUpTheRanks, MSGBOX_NPC
# 403 "data/maps/Route111/scripts.pory"
	end
# 404 "data/maps/Route111/scripts.pory"

# 405 "data/maps/Route111/scripts.pory"
Route111_EventScript_Man2::
# 406 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WinstrateFamilyDestroyedMe, MSGBOX_NPC
# 407 "data/maps/Route111/scripts.pory"
	end
# 408 "data/maps/Route111/scripts.pory"

# 409 "data/maps/Route111/scripts.pory"
Route111_EventScript_Hiker::
# 410 "data/maps/Route111/scripts.pory"
	lock
# 411 "data/maps/Route111/scripts.pory"
	faceplayer
# 412 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_MIRAGE_TOWER_STATE, 3, Route111_EventScript_HikerMirageTowerGone
# 413 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_MIRAGE_TOWER_STATE, 2, Route111_EventScript_HikerMirageTowerDisintegrated
# 414 "data/maps/Route111/scripts.pory"
	goto_if_set FLAG_MIRAGE_TOWER_VISIBLE, Route111_EventScript_HikerMirageTowerVisible
# 415 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ShouldBeMirageTowerAroundHere, MSGBOX_DEFAULT
# 416 "data/maps/Route111/scripts.pory"
	release
# 417 "data/maps/Route111/scripts.pory"
	end
# 418 "data/maps/Route111/scripts.pory"

# 419 "data/maps/Route111/scripts.pory"
Route111_EventScript_HikerMirageTowerGone::
# 420 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_MirageTowerHasntBeenSeenSince, MSGBOX_DEFAULT
# 421 "data/maps/Route111/scripts.pory"
	release
# 422 "data/maps/Route111/scripts.pory"
	end
# 423 "data/maps/Route111/scripts.pory"

# 424 "data/maps/Route111/scripts.pory"
Route111_EventScript_HikerMirageTowerDisintegrated::
# 425 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ThatWasShockingSandRainedDown, MSGBOX_DEFAULT
# 426 "data/maps/Route111/scripts.pory"
	release
# 427 "data/maps/Route111/scripts.pory"
	end
# 428 "data/maps/Route111/scripts.pory"

# 429 "data/maps/Route111/scripts.pory"
Route111_EventScript_HikerMirageTowerVisible::
# 430 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_MirageTowerClearlyVisible, MSGBOX_DEFAULT
# 431 "data/maps/Route111/scripts.pory"
	release
# 432 "data/maps/Route111/scripts.pory"
	end
# 433 "data/maps/Route111/scripts.pory"

# 434 "data/maps/Route111/scripts.pory"
Route111_EventScript_RockSmashTipFatMan::
# 435 "data/maps/Route111/scripts.pory"
	lockall
# 436 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ROCK_SMASH_MAN, Common_Movement_FacePlayer
# 437 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 438 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_MauvilleUncleToldMeToTakeRockSmash, MSGBOX_DEFAULT
# 439 "data/maps/Route111/scripts.pory"
	closemessage
# 440 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ROCK_SMASH_MAN, Common_Movement_FaceOriginalDirection
# 441 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 442 "data/maps/Route111/scripts.pory"
	releaseall
# 443 "data/maps/Route111/scripts.pory"
	end
# 444 "data/maps/Route111/scripts.pory"

# 445 "data/maps/Route111/scripts.pory"
Route111_EventScript_Drew::
# 446 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_DREW, Route111_Text_DrewIntro, Route111_Text_DrewDefeat
# 447 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_DrewPostBattle, MSGBOX_AUTOCLOSE
# 448 "data/maps/Route111/scripts.pory"
	end
# 449 "data/maps/Route111/scripts.pory"

# 450 "data/maps/Route111/scripts.pory"
Route111_EventScript_Heidi::
# 451 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_HEIDI, Route111_Text_HeidiIntro, Route111_Text_HeidiDefeat
# 452 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_HeidiPostBattle, MSGBOX_AUTOCLOSE
# 453 "data/maps/Route111/scripts.pory"
	end
# 454 "data/maps/Route111/scripts.pory"

# 455 "data/maps/Route111/scripts.pory"
Route111_EventScript_Beau::
# 456 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_BEAU, Route111_Text_BeauIntro, Route111_Text_BeauDefeat
# 457 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BeauPostBattle, MSGBOX_AUTOCLOSE
# 458 "data/maps/Route111/scripts.pory"
	end
# 459 "data/maps/Route111/scripts.pory"

# 460 "data/maps/Route111/scripts.pory"
Route111_EventScript_Becky::
# 461 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_BECKY, Route111_Text_BeckyIntro, Route111_Text_BeckyDefeat
# 462 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BeckyPostBattle, MSGBOX_AUTOCLOSE
# 463 "data/maps/Route111/scripts.pory"
	end
# 464 "data/maps/Route111/scripts.pory"

# 465 "data/maps/Route111/scripts.pory"
Route111_EventScript_Dusty::
# 466 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_DUSTY_1, Route111_Text_DustyIntro, Route111_Text_DustyDefeat, Route111_EventScript_RegisterDusty
# 467 "data/maps/Route111/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 468 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route111_EventScript_RematchDusty
# 469 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_DustyPostBattle, MSGBOX_DEFAULT
# 470 "data/maps/Route111/scripts.pory"
	release
# 471 "data/maps/Route111/scripts.pory"
	end
# 472 "data/maps/Route111/scripts.pory"

# 473 "data/maps/Route111/scripts.pory"
Route111_EventScript_RegisterDusty::
# 474 "data/maps/Route111/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 475 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 476 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_DustyRegister, MSGBOX_DEFAULT
# 477 "data/maps/Route111/scripts.pory"
	register_matchcall TRAINER_DUSTY_1
# 478 "data/maps/Route111/scripts.pory"
	release
# 479 "data/maps/Route111/scripts.pory"
	end
# 480 "data/maps/Route111/scripts.pory"

# 481 "data/maps/Route111/scripts.pory"
Route111_EventScript_RematchDusty::
# 482 "data/maps/Route111/scripts.pory"
	trainerbattle_rematch TRAINER_DUSTY_1, Route111_Text_DustyRematchIntro, Route111_Text_DustyRematchDefeat
# 483 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_DustyPostRematch, MSGBOX_AUTOCLOSE
# 484 "data/maps/Route111/scripts.pory"
	end
# 485 "data/maps/Route111/scripts.pory"

# 486 "data/maps/Route111/scripts.pory"
Route111_EventScript_Travis::
# 487 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_TRAVIS, Route111_Text_TravisIntro, Route111_Text_TravisDefeat
# 488 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_TravisPostBattle, MSGBOX_AUTOCLOSE
# 489 "data/maps/Route111/scripts.pory"
	end
# 490 "data/maps/Route111/scripts.pory"

# 491 "data/maps/Route111/scripts.pory"
Route111_EventScript_Irene::
# 492 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_IRENE, Route111_Text_IreneIntro, Route111_Text_IreneDefeat
# 493 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_IrenePostBattle, MSGBOX_AUTOCLOSE
# 494 "data/maps/Route111/scripts.pory"
	end
# 495 "data/maps/Route111/scripts.pory"

# 496 "data/maps/Route111/scripts.pory"
Route111_EventScript_Daisuke::
# 497 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_DAISUKE, Route111_Text_DaisukeIntro, Route111_Text_DaisukeDefeat
# 498 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_DaisukePostBattle, MSGBOX_AUTOCLOSE
# 499 "data/maps/Route111/scripts.pory"
	end
# 500 "data/maps/Route111/scripts.pory"

# 501 "data/maps/Route111/scripts.pory"
Route111_EventScript_Wilton::
# 502 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_WILTON_1, Route111_Text_WiltonIntro, Route111_Text_WiltonDefeat, Route111_EventScript_RegisterWilton
# 503 "data/maps/Route111/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 504 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route111_EventScript_RematchWilton
# 505 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WiltonPostBattle, MSGBOX_DEFAULT
# 506 "data/maps/Route111/scripts.pory"
	release
# 507 "data/maps/Route111/scripts.pory"
	end
# 508 "data/maps/Route111/scripts.pory"

# 509 "data/maps/Route111/scripts.pory"
Route111_EventScript_RegisterWilton::
# 510 "data/maps/Route111/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 511 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 512 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WiltonRegister, MSGBOX_DEFAULT
# 513 "data/maps/Route111/scripts.pory"
	register_matchcall TRAINER_WILTON_1
# 514 "data/maps/Route111/scripts.pory"
	release
# 515 "data/maps/Route111/scripts.pory"
	end
# 516 "data/maps/Route111/scripts.pory"

# 517 "data/maps/Route111/scripts.pory"
Route111_EventScript_RematchWilton::
# 518 "data/maps/Route111/scripts.pory"
	trainerbattle_rematch TRAINER_WILTON_1, Route111_Text_WiltonRematchIntro, Route111_Text_WiltonRematchDefeat
# 519 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WiltonPostRematch, MSGBOX_AUTOCLOSE
# 520 "data/maps/Route111/scripts.pory"
	end
# 521 "data/maps/Route111/scripts.pory"

# 522 "data/maps/Route111/scripts.pory"
Route111_EventScript_Brooke::
# 523 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_BROOKE_1, Route111_Text_BrookeIntro, Route111_Text_BrookeDefeat, Route111_EventScript_RegisterBrooke
# 524 "data/maps/Route111/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 525 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route111_EventScript_RematchBrooke
# 526 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BrookePostBattle, MSGBOX_DEFAULT
# 527 "data/maps/Route111/scripts.pory"
	release
# 528 "data/maps/Route111/scripts.pory"
	end
# 529 "data/maps/Route111/scripts.pory"

# 530 "data/maps/Route111/scripts.pory"
Route111_EventScript_RegisterBrooke::
# 531 "data/maps/Route111/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 532 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 533 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BrookeRegister, MSGBOX_DEFAULT
# 534 "data/maps/Route111/scripts.pory"
	register_matchcall TRAINER_BROOKE_1
# 535 "data/maps/Route111/scripts.pory"
	release
# 536 "data/maps/Route111/scripts.pory"
	end
# 537 "data/maps/Route111/scripts.pory"

# 538 "data/maps/Route111/scripts.pory"
Route111_EventScript_RematchBrooke::
# 539 "data/maps/Route111/scripts.pory"
	trainerbattle_rematch TRAINER_BROOKE_1, Route111_Text_BrookeRematchIntro, Route111_Text_BrookeRematchDefeat
# 540 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BrookePostRematch, MSGBOX_AUTOCLOSE
# 541 "data/maps/Route111/scripts.pory"
	end
# 542 "data/maps/Route111/scripts.pory"

# 543 "data/maps/Route111/scripts.pory"
Route111_EventScript_Hayden::
# 544 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_HAYDEN, Route111_Text_HaydenIntro, Route111_Text_HaydenDefeat
# 545 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_HaydenPostBattle, MSGBOX_AUTOCLOSE
# 546 "data/maps/Route111/scripts.pory"
	end
# 547 "data/maps/Route111/scripts.pory"

# 548 "data/maps/Route111/scripts.pory"
Route111_EventScript_Bianca::
# 549 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_BIANCA, Route111_Text_BiancaIntro, Route111_Text_BiancaDefeat
# 550 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BiancaPostBattle, MSGBOX_AUTOCLOSE
# 551 "data/maps/Route111/scripts.pory"
	end
# 552 "data/maps/Route111/scripts.pory"

# 553 "data/maps/Route111/scripts.pory"
Route111_EventScript_Tyron::
# 554 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_TYRON, Route111_Text_TyronIntro, Route111_Text_TyronDefeat
# 555 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_TyronPostBattle, MSGBOX_AUTOCLOSE
# 556 "data/maps/Route111/scripts.pory"
	end
# 557 "data/maps/Route111/scripts.pory"

# 558 "data/maps/Route111/scripts.pory"
Route111_EventScript_Celina::
# 559 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_CELINA, Route111_Text_CelinaIntro, Route111_Text_CelinaDefeat
# 560 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_CelinaPostBattle, MSGBOX_AUTOCLOSE
# 561 "data/maps/Route111/scripts.pory"
	end
# 562 "data/maps/Route111/scripts.pory"

# 563 "data/maps/Route111/scripts.pory"
Route111_EventScript_Celia::
# 564 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_CELIA, Route111_Text_CeliaIntro, Route111_Text_CeliaDefeat
# 565 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_CeliaPostBattle, MSGBOX_AUTOCLOSE
# 566 "data/maps/Route111/scripts.pory"
	end
# 567 "data/maps/Route111/scripts.pory"

# 568 "data/maps/Route111/scripts.pory"
Route111_EventScript_Bryan::
# 569 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_BRYAN, Route111_Text_BryanIntro, Route111_Text_BryanDefeat
# 570 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BryanPostBattle, MSGBOX_AUTOCLOSE
# 571 "data/maps/Route111/scripts.pory"
	end
# 572 "data/maps/Route111/scripts.pory"

# 573 "data/maps/Route111/scripts.pory"
Route111_EventScript_Branden::
# 574 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_BRANDEN, Route111_Text_BrandenIntro, Route111_Text_BrandenDefeat
# 575 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BrandenPostBattle, MSGBOX_AUTOCLOSE
# 576 "data/maps/Route111/scripts.pory"
	end
# 577 "data/maps/Route111/scripts.pory"

# 578 "data/maps/Route111/scripts.pory"
Route111_EventScript_TrainerHillSign::
# 579 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_TrainerHillSign, MSGBOX_SIGN
# 580 "data/maps/Route111/scripts.pory"
	end
# 581 "data/maps/Route111/scripts.pory"

# 582 "data/maps/Route111/scripts.pory"
Route111_Text_BattleOurFamily:
# 583 "data/maps/Route111/scripts.pory"
	.string "Hello! I take it you're a traveler.\p"
# 584 "data/maps/Route111/scripts.pory"
	.string "How's this? What do you say to taking\n"
# 585 "data/maps/Route111/scripts.pory"
	.string "on our family of four in a series of\l"
# 586 "data/maps/Route111/scripts.pory"
	.string "POKéMON battles?$"
# 587 "data/maps/Route111/scripts.pory"

# 588 "data/maps/Route111/scripts.pory"
Route111_Text_IsThatSo:
# 589 "data/maps/Route111/scripts.pory"
	.string "Is that so?\n"
# 590 "data/maps/Route111/scripts.pory"
	.string "Drop in, if you change your mind!$"
# 591 "data/maps/Route111/scripts.pory"

# 592 "data/maps/Route111/scripts.pory"
Route111_Text_VictorIntro:
# 593 "data/maps/Route111/scripts.pory"
	.string "That's the spirit! I like you!$"
# 594 "data/maps/Route111/scripts.pory"

# 595 "data/maps/Route111/scripts.pory"
Route111_Text_VictorDefeat:
# 596 "data/maps/Route111/scripts.pory"
	.string "Aiyah!\n"
# 597 "data/maps/Route111/scripts.pory"
	.string "You're a lot tougher than I expected!$"
# 598 "data/maps/Route111/scripts.pory"

# 599 "data/maps/Route111/scripts.pory"
Route111_Text_VictorPostBattle:
# 600 "data/maps/Route111/scripts.pory"
	.string "Hey, all!\n"
# 601 "data/maps/Route111/scripts.pory"
	.string "I've found a pretty strong TRAINER!$"
# 602 "data/maps/Route111/scripts.pory"

# 603 "data/maps/Route111/scripts.pory"
Route111_Text_VictoriaIntro:
# 604 "data/maps/Route111/scripts.pory"
	.string "Oh, my goodness! Aren't you young?\p"
# 605 "data/maps/Route111/scripts.pory"
	.string "You must be quite the TRAINER to beat\n"
# 606 "data/maps/Route111/scripts.pory"
	.string "my husband, though.\p"
# 607 "data/maps/Route111/scripts.pory"
	.string "It's my turn to battle now!$"
# 608 "data/maps/Route111/scripts.pory"

# 609 "data/maps/Route111/scripts.pory"
Route111_Text_VictoriaDefeat:
# 610 "data/maps/Route111/scripts.pory"
	.string "Oh, gosh!\n"
# 611 "data/maps/Route111/scripts.pory"
	.string "I can't get over how strong you are!$"
# 612 "data/maps/Route111/scripts.pory"

# 613 "data/maps/Route111/scripts.pory"
Route111_Text_VictoriaPostBattle:
# 614 "data/maps/Route111/scripts.pory"
	.string "There's a strong TRAINER here!\n"
# 615 "data/maps/Route111/scripts.pory"
	.string "This one's really strong!$"
# 616 "data/maps/Route111/scripts.pory"

# 617 "data/maps/Route111/scripts.pory"
Route111_Text_ViviIntro:
# 618 "data/maps/Route111/scripts.pory"
	.string "You're stronger than Mommy? Wow!\p"
# 619 "data/maps/Route111/scripts.pory"
	.string "But I'm strong, too!\n"
# 620 "data/maps/Route111/scripts.pory"
	.string "Really! Honestly!$"
# 621 "data/maps/Route111/scripts.pory"

# 622 "data/maps/Route111/scripts.pory"
Route111_Text_ViviDefeat:
# 623 "data/maps/Route111/scripts.pory"
	.string "Huh? Did I just lose?$"
# 624 "data/maps/Route111/scripts.pory"

# 625 "data/maps/Route111/scripts.pory"
Route111_Text_ViviPostBattle:
# 626 "data/maps/Route111/scripts.pory"
	.string "This stinks…\p"
# 627 "data/maps/Route111/scripts.pory"
	.string "…Snivel… Grandma!$"
# 628 "data/maps/Route111/scripts.pory"

# 629 "data/maps/Route111/scripts.pory"
Route111_Text_VickyIntro:
# 630 "data/maps/Route111/scripts.pory"
	.string "How dare you make my granddaughter\n"
# 631 "data/maps/Route111/scripts.pory"
	.string "cry!\p"
# 632 "data/maps/Route111/scripts.pory"
	.string "For that, I'm going to smack you!\n"
# 633 "data/maps/Route111/scripts.pory"
	.string "Prepare to lose!$"
# 634 "data/maps/Route111/scripts.pory"

# 635 "data/maps/Route111/scripts.pory"
Route111_Text_VickyDefeat:
# 636 "data/maps/Route111/scripts.pory"
	.string "Kwah! You are strong…\n"
# 637 "data/maps/Route111/scripts.pory"
	.string "My granddaughter was right…$"
# 638 "data/maps/Route111/scripts.pory"

# 639 "data/maps/Route111/scripts.pory"
Route111_Text_VickyPostBattle:
# 640 "data/maps/Route111/scripts.pory"
	.string "If you're not in any hurry,\n"
# 641 "data/maps/Route111/scripts.pory"
	.string "visit with us awhile.$"
# 642 "data/maps/Route111/scripts.pory"

# 643 "data/maps/Route111/scripts.pory"
Route111_Text_ToughToKeepWinningUpTheRanks:
# 644 "data/maps/Route111/scripts.pory"
	.string "If you don't raise your POKéMON some\n"
# 645 "data/maps/Route111/scripts.pory"
	.string "more, it could be tough to keep winning\l"
# 646 "data/maps/Route111/scripts.pory"
	.string "up through the ranks.\p"
# 647 "data/maps/Route111/scripts.pory"
	.string "I've heard the POKéMON LEAGUE's\n"
# 648 "data/maps/Route111/scripts.pory"
	.string "ELITE FOUR are far stronger than\l"
# 649 "data/maps/Route111/scripts.pory"
	.string "any GYM LEADER.$"
# 650 "data/maps/Route111/scripts.pory"

# 651 "data/maps/Route111/scripts.pory"
Route111_Text_WinstrateFamilyDestroyedMe:
# 652 "data/maps/Route111/scripts.pory"
	.string "I challenged the WINSTRATE family,\n"
# 653 "data/maps/Route111/scripts.pory"
	.string "but four matches in a row is tough\l"
# 654 "data/maps/Route111/scripts.pory"
	.string "going… They destroyed me.$"
# 655 "data/maps/Route111/scripts.pory"

# 656 "data/maps/Route111/scripts.pory"
Route111_Text_RouteSignMauville:
# 657 "data/maps/Route111/scripts.pory"
	.string "ROUTE 111\n"
# 658 "data/maps/Route111/scripts.pory"
	.string "{DOWN_ARROW} MAUVILLE CITY$"
# 659 "data/maps/Route111/scripts.pory"

# 660 "data/maps/Route111/scripts.pory"
Route111_Text_WinstrateHouseSign:
# 661 "data/maps/Route111/scripts.pory"
	.string "“Our family's hearts beat as one!”\n"
# 662 "data/maps/Route111/scripts.pory"
	.string "THE WINSTRATE'S HOUSE$"
# 663 "data/maps/Route111/scripts.pory"

# 664 "data/maps/Route111/scripts.pory"
Route111_Text_RouteSign112:
# 665 "data/maps/Route111/scripts.pory"
	.string "ROUTE 111\n"
# 666 "data/maps/Route111/scripts.pory"
	.string "{LEFT_ARROW} ROUTE 112$"
# 667 "data/maps/Route111/scripts.pory"

# 668 "data/maps/Route111/scripts.pory"
Route111_Text_RouteSign113:
# 669 "data/maps/Route111/scripts.pory"
	.string "ROUTE 111\n"
# 670 "data/maps/Route111/scripts.pory"
	.string "{LEFT_ARROW} ROUTE 113$"
# 671 "data/maps/Route111/scripts.pory"

# 672 "data/maps/Route111/scripts.pory"
Route111_Text_OldLadysRestStopSign:
# 673 "data/maps/Route111/scripts.pory"
	.string "OLD LADY'S REST STOP\n"
# 674 "data/maps/Route111/scripts.pory"
	.string "“Come in and rest your tired bones.”$"
# 675 "data/maps/Route111/scripts.pory"

# 676 "data/maps/Route111/scripts.pory"
Route111_Text_TrainerTipsSpAtkSpDef:
# 677 "data/maps/Route111/scripts.pory"
	.string "TRAINER TIPS\p"
# 678 "data/maps/Route111/scripts.pory"
	.string "One of the indicators of a POKéMON's\n"
# 679 "data/maps/Route111/scripts.pory"
	.string "powerfulness is SP. ATK. It stands for\l"
# 680 "data/maps/Route111/scripts.pory"
	.string "“SPECIAL ATTACK.”\p"
# 681 "data/maps/Route111/scripts.pory"
	.string "Likewise, SP. DEF stands for “SPECIAL\n"
# 682 "data/maps/Route111/scripts.pory"
	.string "DEFENSE.”$"
# 683 "data/maps/Route111/scripts.pory"

# 684 "data/maps/Route111/scripts.pory"
Route111_Text_ShouldBeMirageTowerAroundHere:
# 685 "data/maps/Route111/scripts.pory"
	.string "There should be a tower made of sand\n"
# 686 "data/maps/Route111/scripts.pory"
	.string "around here somewhere.\p"
# 687 "data/maps/Route111/scripts.pory"
	.string "But for some reason, it can be seen\n"
# 688 "data/maps/Route111/scripts.pory"
	.string "sometimes, and sometimes not.\p"
# 689 "data/maps/Route111/scripts.pory"
	.string "That's why I call it the MIRAGE TOWER.$"
# 690 "data/maps/Route111/scripts.pory"

# 691 "data/maps/Route111/scripts.pory"
Route111_Text_MirageTowerClearlyVisible:
# 692 "data/maps/Route111/scripts.pory"
	.string "I see it!\n"
# 693 "data/maps/Route111/scripts.pory"
	.string "The tower of sand!\p"
# 694 "data/maps/Route111/scripts.pory"
	.string "The sand tower they called a mirage\n"
# 695 "data/maps/Route111/scripts.pory"
	.string "is clearly visible!\p"
# 696 "data/maps/Route111/scripts.pory"
	.string "But it looks so fragile…\n"
# 697 "data/maps/Route111/scripts.pory"
	.string "It could crumble away anytime…\p"
# 698 "data/maps/Route111/scripts.pory"
	.string "I want to go inside it, but I can't\n"
# 699 "data/maps/Route111/scripts.pory"
	.string "get my courage up for it…$"
# 700 "data/maps/Route111/scripts.pory"

# 701 "data/maps/Route111/scripts.pory"
Route111_Text_ThatWasShockingSandRainedDown:
# 702 "data/maps/Route111/scripts.pory"
	.string "Whoa…\n"
# 703 "data/maps/Route111/scripts.pory"
	.string "That was shocking.\p"
# 704 "data/maps/Route111/scripts.pory"
	.string "Sand rained down in chunks all of\n"
# 705 "data/maps/Route111/scripts.pory"
	.string "a sudden.\p"
# 706 "data/maps/Route111/scripts.pory"
	.string "What was it like inside?\n"
# 707 "data/maps/Route111/scripts.pory"
	.string "Were there sandy ghosts and such?$"
# 708 "data/maps/Route111/scripts.pory"

# 709 "data/maps/Route111/scripts.pory"
Route111_Text_MirageTowerHasntBeenSeenSince:
# 710 "data/maps/Route111/scripts.pory"
	.string "Since I spoke to you, the tower of sand\n"
# 711 "data/maps/Route111/scripts.pory"
	.string "hasn't been seen.\p"
# 712 "data/maps/Route111/scripts.pory"
	.string "Perhaps it really was\n"
# 713 "data/maps/Route111/scripts.pory"
	.string "the MIRAGE TOWER…$"
# 714 "data/maps/Route111/scripts.pory"

# 715 "data/maps/Route111/scripts.pory"
Route111_Text_ClawFossilDisappeared:
# 716 "data/maps/Route111/scripts.pory"
	.string "The CLAW FOSSIL disappeared into\n"
# 717 "data/maps/Route111/scripts.pory"
	.string "the sand…$"
# 718 "data/maps/Route111/scripts.pory"

# 719 "data/maps/Route111/scripts.pory"
Route111_Text_RootFossilDisappeared:
# 720 "data/maps/Route111/scripts.pory"
	.string "The ROOT FOSSIL disappeared into\n"
# 721 "data/maps/Route111/scripts.pory"
	.string "the sand…$"
# 722 "data/maps/Route111/scripts.pory"

# 723 "data/maps/Route111/scripts.pory"
Route111_Text_MauvilleUncleToldMeToTakeRockSmash:
# 724 "data/maps/Route111/scripts.pory"
	.string "Oh, no!\p"
# 725 "data/maps/Route111/scripts.pory"
	.string "My uncle in MAUVILLE told me to take\n"
# 726 "data/maps/Route111/scripts.pory"
	.string "ROCK SMASH with me if I was going to\l"
# 727 "data/maps/Route111/scripts.pory"
	.string "ROUTE 111!\p"
# 728 "data/maps/Route111/scripts.pory"
	.string "My uncle? He lives across from\n"
# 729 "data/maps/Route111/scripts.pory"
	.string "the bike shop in MAUVILLE.$"
# 730 "data/maps/Route111/scripts.pory"

# 731 "data/maps/Route111/scripts.pory"
Route111_Text_TrainerHillSign:
# 732 "data/maps/Route111/scripts.pory"
	.string "{RIGHT_ARROW} TRAINER HILL ENTRANCE\p"
# 733 "data/maps/Route111/scripts.pory"
	.string "“Scale the heights, you hot-blooded\n"
# 734 "data/maps/Route111/scripts.pory"
	.string "TRAINERS!”$"
