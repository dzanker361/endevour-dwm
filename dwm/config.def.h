/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int gappx     = 2;        /* gaps between windows */
static const unsigned int snap      = 28;       /* snap pixel */
static const int swallowfloating    = 1;        /* 1 means swallow floating windows by default */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]               = { "Iosevka Nerd Font:size=14", "fontawesome:size=14", "Font Awesome Brands:size=14" };
static const char dmenufont[]            = "Source Code Pro Nerd Font:size=13";

/* Gruvbox-Dark colors */
static const char col_gray1[]       = "#282828";  /* Background */
static const char col_gray2[]       = "#504945";  /* Border */
static const char col_gray3[]       = "#ebdbb2";  /* Foreground  */
static const char col_gray4[]       = "#d5c4a1";  /* Accent  */
static const char col_cyan[]        = "#404946";  /* Accent (lišta s názvem spuštěného programu */

/* Gruvbox-Light colors */
static const char s_base03[]        = "#ebdbb2";  /* Background (světle béžová) */
static const char s_base02[]        = "#bdae93";  /* Border (světle hnědá) */
static const char s_base01[]        = "#3c3836";  /* Foreground (tmavě šedá) */
static const char s_base00[]        = "#504945";  /* Accent (tmavě hnědá) */
static const char s_base0[]         = "#665c54";  /* Accent (středně hnědá) */
static const char s_base1[]         = "#7c6f64";  /* Accent (středně hnědá) */
static const char s_base2[]         = "#928374";  /* Accent (světle hnědá) */
static const char s_base3[]         = "#a89984";  /* Accent (světle hnědá) */

/* Gruvbox-Muted colors (třetí téma) */
static const char gb_muted_bg[]     = "#32302f";  /* Background (tmavě šedohnědá) */
static const char gb_muted_fg[]     = "#a89984";  /* Foreground (světle hnědá) */
static const char gb_muted_border[] = "#665c54";  /* Border (středně hnědá) */
static const char gb_muted_bg2[]     = "#8ec07c";  /* Background (tmavě šedohnědá) */
static const char gb_muted_fg2[]     = "#3d4220";  /* Foreground (světle hnědá) */

/* bar opacity percent*/
static const unsigned int baralpha = 0xff;
static const unsigned int borderalpha = OPAQUE;


static const char *colors[][3] = {
    /*               fg         bg         border   */
    { col_gray3, col_gray1, col_gray2 },      /* SchemeNorm dark */
    { col_gray4, col_cyan,  col_gray2 },      /* SchemeSel dark */
    { s_base01, s_base03, s_base02 },               /* SchemeNorm light */
    { s_base00, s_base3,  s_base02 },               /* SchemeSel light */
    { gb_muted_fg, gb_muted_bg, gb_muted_border },  /* SchemeNorm muted  */
    { gb_muted_fg2, gb_muted_bg2, col_gray2 },  /* SchemeSel muted  */
};

static const unsigned int alphas[][3] = {
    /*               fg      bg        border */
    [0] = { OPAQUE, baralpha, borderalpha },  /* SchemeNorm dark */
    [1] = { OPAQUE, baralpha, borderalpha },  /* SchemeSel dark */
    [2] = { OPAQUE, baralpha, borderalpha },  /* SchemeNorm light */
    [3] = { OPAQUE, baralpha, borderalpha },  /* SchemeSel light */
    [4] = { OPAQUE, baralpha, borderalpha },  /* SchemeNorm muted */
    [5] = { OPAQUE, baralpha, borderalpha },  /* SchemeSel muted */
};

/* tagging */
/* static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" }; */
static const char *tags[] = { "", "🐱", "", "", "", "Ƹ̵̡Ӝ̵̨̄Ʒ", "󰨜", "󰽰", "󰍣" };
static const char *defaulttagapps[] = { "st", "brave", "thunar", NULL, NULL, NULL, NULL, "st -e termusic", "ferdium" };


static const char *tagsel[][2] = {
    { "#d65d0e", "#2D2D2D" },  /* Oranžová text, tmavě šedivé pozadí */
    { "#d79921", "#2D2D2D" },  /* Žlutá text, tmavě šedivé pozadí */
    { "#98971a", "#2D2D2D" },  /* Zelená text, tmavě šedivé pozadí */
    { "#458588", "#2D2D2D" },  /* Modrá text, tmavě šedivé pozadí */
    { "#b16286", "#2D2D2D" },  /* Fialová text, tmavě šedivé pozadí */
    { "#d3869b", "#2D2D2D" },  /* Růžová text, tmavě šedivé pozadí */
    { "#076678", "#2D2D2D" },  /* Tmavě modrá text, tmavě šedivé pozadí */
    { "#83a598", "#2D2D2D" },  /* Levandulová text, tmavě šedivé pozadí */
    { "#cc241d", "#2D2D2D" },  /* Červená text, tmavě šedivé pozadí */    
};

static const unsigned int tagalpha[] = { OPAQUE, baralpha };

static const unsigned int ulinepad	= 5;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke	= 1;	/* thickness / height of the underline */
static const unsigned int ulinevoffset	= 0;	/* how far above the bottom of the bar the line should appear */
static const int ulineall 		= 0;	/* 1 to show underline on all tags, 0 for just the active ones */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class     			instance  title     tags mask  isfloating  isterminal  noswallow  monitor */
	{ 	    "st",	          NULL,     NULL,     0,         1,     1,		0,     -1 },
	{ 	   "brave", 	      NULL,     NULL,  1 << 8,    0,     0,		-1,     -1 },
	{      "atril",           NULL,     NULL,   0,        0,     0, 	 0,     -1 },
	{      "okular",          NULL,     NULL,   0,        0,     0, 	 0,     -1 },
	{      "geany",           NULL,     NULL,   1 << 4,   0,     0, 	 0,     -1 },
	{      "termusic",        NULL,     NULL,   0,        1,     0, 	 0,     -1 },	
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;   /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 0;  /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "",      tile },    /* first entry is default */
	{ "󰹣",      NULL },    /* no layout function means floating behavior */
	{ "",      monocle },
	{ "󱗼",      grid },	
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run_history", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *filecmd[]  = { "thunar", NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *rebootcmd[]  = { "shutdown", "-r", "+0", NULL };
static const char *shutdowncmd[]  = { "shutdown", "+0", NULL };
static const char *browsercmd[] = { "brave", NULL };
static const char *up_volume_cmd[] = { "volume-control", "+5%", NULL };
static const char *down_volume_cmd[] = { "volume-control", "-5%", NULL };

/*
static const char *up_volume_cmd[] = { "sh", "-c", "pactl set-sink-volume @DEFAULT_SINK@ +5% && pactl get-sink-volume @DEFAULT_SINK@ | awk '{print $5}'", NULL };
static const char *down_volume_cmd[] = { "sh", "-c", "pactl set-sink-volume @DEFAULT_SINK@ -5% && pactl get-sink-volume @DEFAULT_SINK@ | awk '{print $5}'", NULL };*/

#include "movestack.c"

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,			 		    XK_d, 		spawn,         {.v = dmenucmd } },
	{ MODKEY,                   	XK_x, 		spawn,         {.v = termcmd } },
	{ MODKEY|ControlMask,           XK_x, 		spawn,         SHCMD ("st -c tiled") },	
	{ MODKEY|ControlMask,           XK_Delete, spawn,          {.v = rebootcmd} },
	{ MODKEY|ControlMask,           XK_Escape, spawn,          {.v = shutdowncmd} },
	{ MODKEY,                       XK_w,       spawn, 	       {.v = browsercmd } },
	{ MODKEY,                       XK_e,       spawn, 	       {.v = filecmd } },
	{ MODKEY,                       XK_a,       spawndefault,  {0} },	
	
	{ 0,                       		XK_Pause,  spawn,            SHCMD ("ferdium") },
	{ MODKEY,                       XK_s,      spawn,            SHCMD ("st -e termusic") },
	{ MODKEY|ControlMask,           XK_Return, spawn,            SHCMD ("st -e cava") },
    { MODKEY,                       XK_n,      spawn,            SHCMD ("variety -n &") },
	{ 0, 						    XK_Scroll_Lock,     spawn,   SHCMD("tdrop -ma -w 100% -h 100% -s dropdown st") },
	{ 0, 						    XK_Print,  spawn,   		 SHCMD("flameshot screen") },
	{ MODKEY|ControlMask,           XK_l,      spawn,            SHCMD ("loginctl terminate-user dl") },
	
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,			            XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_g,      setlayout,      {.v = &layouts[3]} },	
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,		                XK_Return, togglefullscr,  {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -5 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +5 } },
	{ MODKEY|ControlMask,           XK_equal,  setgaps,        {.i = 0  } },
	{ MODKEY|ControlMask,           XK_t,      schemeToggle,   {0} },
	{ MODKEY|ControlMask,           XK_space,  schemeCycle,    {0} },	
	
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	
	{ MODKEY|ControlMask,		    XK_q,      quit,           {0} },
	
	{ 0, 			XF86XK_AudioLowerVolume, spawn, {.v = down_volume_cmd } },
	{ 0, 			XF86XK_AudioRaiseVolume, spawn, {.v = up_volume_cmd } },	
/*	{ 0,				XF86XK_AudioLowerVolume,spawn,			{.v = decvol} },	*/
/*	{ 0,				XF86XK_AudioRaiseVolume,spawn,			{.v = incvol} }, */
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

