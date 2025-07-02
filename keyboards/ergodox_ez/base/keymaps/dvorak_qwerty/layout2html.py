import re
import sys

keycodes={}

shift_map={
    '1':'!',
    '2':'@',
    '3':'#',
    '4':'$',
    '5':'%',
    '6':'^',
    '7':'&',
    '8':'*',
    '9':'(',
    '0':')',
    '"':"'",
    ',':'<',
    '.':'>',
    ';':':',
    '\\':'|',
    '/':'?',
    '-':'_',
    '=':'+',
    '[':'{',
    ']':'}',
    '`':'~',
}

basic_codes={
    'KC_MINUS':'-',
    'KC_EQUAL':'=',
    'KC_LEFT_BRACKET':'[',
    'KC_RIGHT_BRACKET':']',
    'KC_BACKSLASH':'\\',
    'KC_BSLS':'\\',
    'KC_SEMICOLON':';',
    'KC_SCLN':';',
    'KC_QUOTE':'"',
    'KC_GRAVE':'`',
    'KC_COMMA':',',
    'KC_DOT':'.',
    'KC_SLASH':'/',
    'KC_UP':'⇧',
    'KC_LEFT':'⇦',
    'KC_RIGHT':'⇨',
    'KC_DOWN':'⇩',
    'KC_LEFT_PAREN':'(',
    'KC_RIGHT_PAREN':')',
    'KC_LEFT_ANGLE_BRACKET':'<',
    'KC_RIGHT_ANGLE_BRACKET':'>',
    'KC_LEFT_CURLY_BRACE':'{',
    'KC_RIGHT_CURLY_BRACE':'}',
}

for letter in 'abcdefghijklmnopqrstuvwxyz0123456789':
    code=f'KC_{letter.upper()}'
    shift=shift_map.get(letter,letter.upper())
    keycodes[code]={
        'tap':letter,
        'shift':shift,
        'hold':shift,
    }

for letter in '0123456789':
    code=f'KC_KP_{letter.upper()}'
    keycodes[code]={
        'tap':letter,
    }

for code in basic_codes.keys():
    letter=basic_codes[code]
    shift=shift_map.get(letter,'')
    keycodes[code]={
        'tap':letter,
    }
    if shift:
        keycodes[code]['shift']=shift
        keycodes[code]['hold']=shift

keycodes['C(S(KC_M))']={'tap':'<img src=icon/mute-mic.png>'}
keycodes['C(S(KC_O))']={'tap':'<img src=icon/camera-off.png>'}
keycodes['TG(LAY_NUM_FN)']={'tap':'<img src=icon/keypad.png>'}
keycodes['MO_TG_NUMFN']={'tap':'<img src=icon/keypad.png>'}
keycodes['LM(LAY_QWERTY_CONTROL, MOD_MASK_CTRL)']={'tap':'<img src=icon/control-qwerty.png>'}
keycodes['LM(LAY_QWERTY_META, MOD_MASK_GUI)']={'tap':'<img src=icon/meta-qwerty.png>'}
keycodes['LM(LAY_QWERTY_ALT, MOD_MASK_ALT)']={'tap':'<img src=icon/alt-qwerty.png>'}
keycodes['KC_LEFT_CTRL']={'tap':'<img src=icon/control.png>'}
keycodes['KC_LEFT_GUI']={'tap':'<img src=icon/meta.png>'}
keycodes['KC_LEFT_ALT']={'tap':'<img src=icon/alt.png>'}
keycodes['KC_NUM_LOCK']={'tap':'<img src=icon/num-lock.png>'}
keycodes['QK_AUTO_SHIFT_TOGGLE']={'tap':'<img src=icon/auto-shift.png>'}
keycodes['KC_MEDIA_PLAY_PAUSE']={'tap':'<img src=icon/play-pause.png>'}
keycodes['KC_MEDIA_NEXT_TRACK']={'tap':'<img src=icon/next-track.png>'}
keycodes['KC_MEDIA_FAST_FORWARD']={'tap':'<img src=icon/fast-forward.png>'}
keycodes['KC_MEDIA_PREV_TRACK']={'tap':'<img src=icon/previous-track.png>'}
keycodes['KC_MEDIA_REWIND']={'tap':'<img src=icon/rewind.png>'}
keycodes['KC_CALCULATOR']={'tap':'<img src=icon/calculator.png>'}
keycodes['KC_VOLU']={'tap':'<img src=icon/volume-up.png>'}
keycodes['KC_VOLD']={'tap':'<img src=icon/volume-down.png>'}
keycodes['KC_PSCR']={'tap':'<img src=icon/screenshot.png>'}
keycodes['KC_DELETE']={'tap':'<img src=icon/delete.png>'}
keycodes['KC_BSPC']={'tap':'<img src=icon/backspace.png>'}
keycodes['KC_ENTER']={'tap':'<img src=icon/enter.png>'}
keycodes['KC_SPACE']={'tap':'<img src=icon/space.png>'}
keycodes['KC_ESC']={'tap':'<img src=icon/escape.png>'}
keycodes['KC_TAB']={'tap':'<img src=icon/tab.png>'}
keycodes['KC_HOME']={'tap':'<img src=icon/home.png>'}
keycodes['KC_END']={'tap':'<img src=icon/end.png>'}
keycodes['C(KC_HOME)']={'tap':'<img src=icon/top.png>'}
keycodes['C(KC_END)']={'tap':'<img src=icon/bottom.png>'}
keycodes['KC_PAGE_UP']={'tap':'<img src=icon/page-up.png>'}
keycodes['KC_PGDN']={'tap':'<img src=icon/page-down.png>'}
keycodes['KC_LEFT_SHIFT']={'tap':'<img src=icon/shift.png>'}
keycodes['KC_RIGHT_SHIFT']={'tap':'<img src=icon/shift.png>'}
keycodes['KC_MEDIA_SELECT']={'tap':'<img src=icon/media-player.png>'}
keycodes['KC_MY_COMPUTER']={'tap':'<img src=icon/folder.png>'}
keycodes['KC_MAIL']={'tap':'<img src=icon/mail.png>'}
keycodes['G(KC_L)']={'tap':'<img src=icon/lock-screen.png>'}
keycodes['A(KC_F4)']={'tap':'<img src=icon/close-window.png>'}
keycodes['KC_FULL_SCREEN']={'tap':'<img src=icon/full-screen.png>'}
keycodes['KC_CAPS']={'tap':'<img src=icon/caps-lock.png>'}
keycodes['QK_CAPS_WORD_TOGGLE']={'tap':'<img src=icon/caps-word.png>'}
keycodes['KC_INS']={'tap':'<img src=icon/insert.png>'}
keycodes['UNICODE_FANCY_ALPHABET_CYCLE']={'tap':'<img src=icon/fancy-alphabet.png>'}
keycodes['UNICODE_FANCY_ALPHABET_MOMENTARY']={'tap':'<img src=icon/fancy-alphabet.png>'}
keycodes['TG(LAY_QWERTY)']={'tap':'qwerty'}
keycodes['MO_TG_QWERTY']={'tap':'qwerty'}
keycodes['KC_KP_PLUS']={'tap':'+'}
keycodes['KC_KP_MINUS']={'tap':'-'}
keycodes['KC_KP_EQUAL']={'tap':'='}
keycodes['KC_KP_DOT']={'tap':'.'}
keycodes['KC_KP_ENTER']={'tap':'<img src=icon/enter.png>'}
keycodes['KC_KP_ASTERISK']={'tap':'*'}
keycodes['KC_KP_SLASH']={'tap':'/'}

def parse_comma_codes(s):
    s=re.sub(',$','',s)
    codes=[]
    nestLevel=0
    start=0
    for i, c in enumerate(s):
        if c == '(':
            nestLevel+=1
        elif c == ')':
            nestLevel-=1
        elif c == ',' and nestLevel==0:
            codes.append(s[start:i].strip())
            start=i+1
    codes.append(s[start:i+1].strip())
    return codes

layouts={}
unicode={}
unicode_used={}
shiftOverrides={}
tapdances={}
mode="none"
context=""
with open('keymap.c', 'r') as file:
    for line in file:
        if(mode=="none"):
            if m:=re.search(r'\[LAY_([A-Z_]+)\]\s*=\s*LAYOUT_ergodox_pretty',line):
                context=m[1].lower()
                layouts[context] = {
                    "tap":[],
                    "hold":["" for i in range(76)],
                    "shift":["" for i in range(76)],
                    "dtap":["" for i in range(76)],
                    "dhold":["" for i in range(76)],
                    "ttap":["" for i in range(76)],
                    "thold":["" for i in range(76)],
                }
                mode="layout"
            elif m:=re.search(r'^const char (u_[a-z_0-9]+)\[\] PROGMEM = "(.*)";$',line):
                unicode[m[1].upper()] = m[2]
            elif m:=re.search(r'eztd_data\[\]',line):
                mode="tapdances"
            elif m:=re.search(r'key_overrides\[\]',line):
                mode="overrides"
        elif (mode=="layout"):
            if re.search(r'^\s*\)',line):
                mode="none"
            elif not re.search(r'^\s*(\/\/)|(\/\*)',line):
                layouts[context]['tap'].extend(parse_comma_codes(line))
        elif (mode=="tapdances"):
            if re.search(r'^\s*\}',line):
                mode="none"
            elif m:=re.search(r'\[([A-Z0-9_]+)\]\s*=\s*([A-Z0-9_]+)\((.*)\),',line):
                func=m[2]
                args=parse_comma_codes(m[3])
                func=re.sub('^EZTD_',"",func)
                func=re.sub('FLOW',"",func)
                func=func.lower().split("_")
                out={}
                for i in range(0,len(func)):
                    if i >= len(args):
                        raise Exception(f"Not enough arguments: {line}")
                    out[func[i]]=args[i]
                tapdances[m[1]] = out
        elif (mode=="overrides"):
            if re.search(r'^\s*\}',line):
                mode="none"
            elif m:=re.search(r'MOD_MASK_SHIFT,\s*([^,]+),\s*(.+)\),$',line):
                shiftOverrides[m[1]] = m[2]

def processKey(layout,variant,i,initial):
    keycode=layouts[layout][variant][i]
    if keycode:
        if initial and keycode in shiftOverrides:
            layouts[layout]['shift'][i]=shiftOverrides[keycode]
            if keycode in basic_codes or re.search('^KC_[A-Z0-9]$', keycode):
                layouts[layout]['hold'][i]=shiftOverrides[keycode]
            initial=False
        if keycode in keycodes:
            if variant in keycodes[keycode]:
                layouts[layout][variant][i]=keycodes[keycode][variant]
            elif 'tap' in keycodes[keycode]:
                layouts[layout][variant][i]=keycodes[keycode]['tap']
            if initial and 'shift' in keycodes[keycode]:
                layouts[layout]['shift'][i]=keycodes[keycode]['shift']
            if initial and 'hold' in keycodes[keycode]:
                layouts[layout]['hold'][i]=keycodes[keycode]['hold']
        elif m:=re.search(r'^UM\((.*)\)$',keycode):
            layouts[layout][variant][i]=unicode[m[1]]
            unicode_used[m[1]] = 1
        elif m:=re.search(r'^KC_(.*)$',keycode):
            layouts[layout][variant][i]=m[1]
        elif m:=re.search(r'^TD\((.*)\)$',keycode):
            td=tapdances[m[1]]
            for tdVariant in td:
                layouts[layout][tdVariant][i]=td[tdVariant]
                processKey(layout, tdVariant, i, False)
        elif re.search('[A-Z]_[A-Z0-9]',keycode):
            layouts[layout][variant][i]=re.sub('_','<br>',keycode.lower())
        elif keycode == 'XXXXXXX':
            layouts[layout][variant][i]=''


for layout in layouts:
    for variant in layouts[layout]:
        for i in range(0,len(layouts[layout][variant])):
            processKey(layout, variant, i, True)

positions=[
    {"class":"key lhnd","top":"10.5","left":"4"},
    {"class":"key lhnd","top":"9.9","left":"10.5"},
    {"class":"key lhnd","top":"7.5","left":"15.6"},
    {"class":"key lhnd","top":"6.5","left":"20.7"},
    {"class":"key lhnd","top":"7.8","left":"25.7"},
    {"class":"key lhnd","top":"8.5","left":"30.8"},
    {"class":"key lhnd","top":"8.5","left":"36"},
    {"class":"key rhnd","top":"8.5","left":"63.9"},
    {"class":"key rhnd","top":"8.5","left":"69.3"},
    {"class":"key rhnd","top":"7.8","left":"74"},
    {"class":"key rhnd","top":"6.5","left":"79.3"},
    {"class":"key rhnd","top":"7.5","left":"84.4"},
    {"class":"key rhnd","top":"9.9","left":"89.6"},
    {"class":"key rhnd","top":"10.5","left":"96"},

    {"class":"key lhnd","top":"24.4","left":"4"},
    {"class":"key lhnd","top":"23.8","left":"10.5"},
    {"class":"key lhnd","top":"21.4","left":"15.6"},
    {"class":"key lhnd","top":"20.4","left":"20.7"},
    {"class":"key lhnd","top":"20.8","left":"25.7"},
    {"class":"key lhnd","top":"21.5","left":"30.8"},
    {"class":"key lhnd","top":"25.5","left":"36"},
    {"class":"key rhnd","top":"25.5","left":"63.9"},
    {"class":"key rhnd","top":"22.7","left":"69.3"},
    {"class":"key rhnd","top":"20.8","left":"74"},
    {"class":"key rhnd","top":"20.4","left":"79.3"},
    {"class":"key rhnd","top":"21.4","left":"84.4"},
    {"class":"key rhnd","top":"23.8","left":"89.6"},
    {"class":"key rhnd","top":"24.4","left":"96"},

    {"class":"key lhnd","top":"37.5","left":"4"},
    {"class":"key lhnd","top":"38.8","left":"10.5"},
    {"class":"key lhnd","top":"36.4","left":"15.6"},
    {"class":"key lhnd","top":"35.4","left":"20.7"},
    {"class":"key lhnd","top":"35.8","left":"25.7"},
    {"class":"key lhnd","top":"36.5","left":"30.8"},
    {"class":"key rhnd","top":"37.7","left":"69.3"},
    {"class":"key rhnd","top":"35.8","left":"74"},
    {"class":"key rhnd","top":"35.4","left":"79.3"},
    {"class":"key rhnd","top":"36.4","left":"84.4"},
    {"class":"key rhnd","top":"38.8","left":"89.6"},
    {"class":"key rhnd","top":"37.5","left":"96"},

    {"class":"key lhnd","top":"51.8","left":"4"},
    {"class":"key lhnd","top":"51","left":"10.5"},
    {"class":"key lhnd","top":"49","left":"15.6"},
    {"class":"key lhnd","top":"48","left":"20.7"},
    {"class":"key lhnd","top":"49","left":"25.7"},
    {"class":"key lhnd","top":"50","left":"30.8"},
    {"class":"key lhnd","top":"47","left":"36"},
    {"class":"key rhnd","top":"47","left":"63.9"},
    {"class":"key rhnd","top":"50","left":"69.3"},
    {"class":"key rhnd","top":"49","left":"74"},
    {"class":"key rhnd","top":"48","left":"79.3"},
    {"class":"key rhnd","top":"49","left":"84.4"},
    {"class":"key rhnd","top":"51","left":"89.6"},
    {"class":"key rhnd","top":"51.8","left":"96"},

    {"class":"key lhnd","top":"66","left":"5"},
    {"class":"key lhnd","top":"66","left":"10.5"},
    {"class":"key lhnd","top":"63","left":"15.6"},
    {"class":"key lhnd","top":"62","left":"20.7"},
    {"class":"key lhnd","top":"63","left":"25.7"},
    {"class":"key rhnd","top":"63","left":"74"},
    {"class":"key rhnd","top":"62","left":"79.3"},
    {"class":"key rhnd","top":"63","left":"84.4"},
    {"class":"key rhnd","top":"66","left":"89.6"},
    {"class":"key rhnd","top":"66","left":"95"},

    {"class":"key lthb","top":"62","left":"41"},
    {"class":"key lthb","top":"68.6","left":"45.2"},
    {"class":"key rthb","top":"65","left":"54.8"},
    {"class":"key rthb","top":"58.2","left":"59"},

    {"class":"key lthb","top":"80.2","left":"43.3"},
    {"class":"key rthb","top":"77","left":"56.7"},

    {"class":"key lthb","top":"73","left":"33.5"},
    {"class":"key lthb","top":"79","left":"38"},
    {"class":"key lthb","top":"92.6","left":"41.5"},
    {"class":"key rthb","top":"89.4","left":"58.6"},
    {"class":"key rthb","top":"77","left":"62"},
    {"class":"key rthb","top":"71","left":"66.8"},
]

def printStyle():
    print('<style>')
    print('.layout{line-height:1.1;font-size:3vw;width:100%;aspect-ratio:2.692;position:relative;background:center/cover url(\'../../../ergodox_ez.svg\')}')
    print('.layout .key{position:absolute;transform:translate(-50%,-50%)}')
    print('.layout .key img{max-width:3vw}')
    print('.layout .lthb{transform:rotate(24deg) translate(-50%,-50%)}')
    print('.layout .rthb{transform:rotate(-24deg) translate(-50%,-50%)}')
    print('</style>')

def printLayout(title, layout):
    print(f'### {title}')
    print('<div class=layout>')
    for i in range(0,min(len(layout),len(positions))):
        text = layout[i]
        pos = positions[i]
        cls = pos["class"]
        top = pos["top"]
        left = pos["left"]
        l = len(text)
        font = max(30,100 if l<=2 else 0.7**(l-2)*100)
        font = "" if font==100 else "{:.1f}".format(font)
        font = "" if not font else f";font-size:{font}%"
        print(f'<div class="{cls}" style="top:{top}%;left:{left}%{font}">{text}</div>')
    print('</div>')
    print('')


printStyle()
for layout in layouts:
    for variant in layouts[layout]:
        printLayout(f"{layout} {variant}",layouts[layout][variant])


for c in unicode:
    if c not in unicode_used:
        print(f"not used: {c} {unicode[c]}", file=sys.stderr)
