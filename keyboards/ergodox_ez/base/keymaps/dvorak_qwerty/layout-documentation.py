import re
import sys
import html
import base64
import os

os.makedirs('layers', exist_ok=True)

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
    "'":'"',
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
    'KC_QUOTE':"'",
    'KC_UNDERSCORE':'_',
    'KC_GRAVE':'`',
    'KC_COMMA':',',
    'KC_DOT':'.',
    'KC_SLASH':'/',
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

keycodes['C(S(KC_M))']={'tap':'icon/mute-mic.svg'}
keycodes['C(S(KC_O))']={'tap':'icon/camera-off.svg'}
keycodes['TG(LAY_NUM_FN)']={'tap':'icon/keypad.svg'}
keycodes['MO_TG_NUMFN']={'tap':'icon/keypad.svg'}
keycodes['LM(LAY_QWERTY_CONTROL, MOD_MASK_CTRL)']={'tap':'icon/control-qwerty.svg'}
keycodes['LM(LAY_QWERTY_META, MOD_MASK_GUI)']={'tap':'icon/meta-qwerty.svg'}
keycodes['LM(LAY_QWERTY_ALT, MOD_MASK_ALT)']={'tap':'icon/alt-qwerty.svg'}
keycodes['KC_LEFT_CTRL']={'tap':'icon/control.svg'}
keycodes['KC_LEFT_GUI']={'tap':'icon/meta.svg'}
keycodes['KC_LEFT_ALT']={'tap':'icon/alt.svg'}
keycodes['KC_NUM_LOCK']={'tap':'icon/num-lock.svg'}
keycodes['QK_AUTO_SHIFT_TOGGLE']={'tap':'icon/auto-shift.svg'}
keycodes['KC_MEDIA_PLAY_PAUSE']={'tap':'icon/play-pause.svg'}
keycodes['KC_MEDIA_NEXT_TRACK']={'tap':'icon/next-track.svg'}
keycodes['KC_MNXT']={'tap':'icon/next-track.svg'}
keycodes['KC_MEDIA_FAST_FORWARD']={'tap':'icon/fast-forward.svg'}
keycodes['KC_MEDIA_PREV_TRACK']={'tap':'icon/previous-track.svg'}
keycodes['KC_MEDIA_REWIND']={'tap':'icon/rewind.svg'}
keycodes['KC_CALCULATOR']={'tap':'icon/calculator.svg'}
keycodes['KC_VOLU']={'tap':'icon/volume-up.svg'}
keycodes['KC_AUDIO_MUTE']={'tap':'icon/mute-speaker.svg'}
keycodes['KC_VOLD']={'tap':'icon/volume-down.svg'}
keycodes['KC_PRINT_SCREEN']={'tap':'icon/screenshot.svg'}
keycodes['KC_PSCR']={'tap':'icon/screenshot.svg'}
keycodes['KC_DELETE']={'tap':'icon/delete.svg'}
keycodes['KC_BSPC']={'tap':'icon/backspace.svg'}
keycodes['KC_ENTER']={'tap':'icon/enter.svg'}
keycodes['KC_SPACE']={'tap':'icon/space.svg'}
keycodes['KC_ESC']={'tap':'icon/escape.svg'}
keycodes['KC_TAB']={'tap':'icon/tab.svg'}
keycodes['KC_HOME']={'tap':'icon/home.svg'}
keycodes['KC_END']={'tap':'icon/end.svg'}
keycodes['C(KC_HOME)']={'tap':'icon/top.svg'}
keycodes['C(KC_END)']={'tap':'icon/bottom.svg'}
keycodes['KC_PAGE_UP']={'tap':'icon/page-up.svg'}
keycodes['KC_PGDN']={'tap':'icon/page-down.svg'}
keycodes['KC_LEFT_SHIFT']={'tap':'icon/shift.svg'}
keycodes['KC_RIGHT_SHIFT']={'tap':'icon/shift.svg'}
keycodes['KC_RSFT']={'tap':'icon/shift.svg'}
keycodes['KC_LSFT']={'tap':'icon/shift.svg'}
keycodes['KC_MEDIA_SELECT']={'tap':'icon/media-player.svg'}
keycodes['KC_MY_COMPUTER']={'tap':'icon/folder.svg'}
keycodes['KC_MAIL']={'tap':'icon/mail.svg'}
keycodes['G(KC_L)']={'tap':'icon/lock-screen.svg'}
keycodes['A(KC_F4)']={'tap':'icon/close-window.svg'}
keycodes['KC_FULL_SCREEN']={'tap':'icon/full-screen.svg'}
keycodes['KC_CAPS']={'tap':'icon/caps-lock.svg'}
keycodes['QK_CAPS_WORD_TOGGLE']={'tap':'icon/caps-word.svg'}
keycodes['KC_INS']={'tap':'icon/insert.svg'}
keycodes['UNICODE_FANCY_ALPHABET_CYCLE']={'tap':'icon/fancy-alphabet.svg'}
keycodes['UNICODE_FANCY_ALPHABET_MOMENTARY']={'tap':'icon/fancy-alphabet.svg'}
keycodes['UFA_DS']={'tap':'icon/fancy-double-struck.svg'}
keycodes['UFA_CIR']={'tap':'icon/fancy-circled.svg'}
keycodes['C(KC_C)']={'tap':'icon/copy.svg'}
keycodes['C(KC_X)']={'tap':'icon/cut.svg'}
keycodes['C(KC_V)']={'tap':'icon/paste.svg'}
keycodes['C(KC_N)']={'tap':'icon/new.svg'}
keycodes['C(KC_O)']={'tap':'icon/open.svg'}
keycodes['C(KC_A)']={'tap':'icon/select-all.svg'}
keycodes['C(KC_S)']={'tap':'icon/save.svg'}
keycodes['C(KC_Z)']={'tap':'icon/undo.svg'}
keycodes['C(KC_Q)']={'tap':'icon/quit.svg'}
keycodes['C(KC_F)']={'tap':'icon/find.svg'}
keycodes['C(KC_P)']={'tap':'icon/print.svg'}
keycodes['C(KC_G)']={'tap':'icon/find-again.svg'}
keycodes['C(KC_T)']={'tap':'icon/new-tab.svg'}
keycodes['C(KC_EQUAL)']={'tap':'icon/zoom-in.svg'}
keycodes['C(KC_MINUS)']={'tap':'icon/zoom-out.svg'}
keycodes['TG(LAY_QWERTY)']={'tap':'qwerty'}
keycodes['MO_TG_QWERTY']={'tap':'qwerty'}
keycodes['KC_KP_PLUS']={'tap':'+'}
keycodes['KC_KP_MINUS']={'tap':'-'}
keycodes['KC_KP_EQUAL']={'tap':'='}
keycodes['KC_KP_DOT']={'tap':'.'}
keycodes['KC_KP_ENTER']={'tap':'icon/enter.svg'}
keycodes['KC_KP_ASTERISK']={'tap':'*'}
keycodes['KC_KP_SLASH']={'tap':'/'}
keycodes['KC_DOLLAR']={'tap':'$'}
keycodes['KC_PERCENT']={'tap':'%'}
keycodes['KC_PERC']={'tap':'%'}
keycodes['KC_UP']={'tap':'icon/up.svg'}
keycodes['KC_LEFT']={'tap':'icon/left.svg'}
keycodes['KC_RIGHT']={'tap':'icon/right.svg'}
keycodes['KC_DOWN']={'tap':'icon/down.svg'}
keycodes['KC_LEFT_PAREN']={'tap':'('}
keycodes['KC_RIGHT_PAREN']={'tap':')'}
keycodes['KC_LEFT_ANGLE_BRACKET']={'tap':'<'}
keycodes['KC_RIGHT_ANGLE_BRACKET']={'tap':'>'}
keycodes['KC_LEFT_CURLY_BRACE']={'tap':'{'}
keycodes['KC_RIGHT_CURLY_BRACE']={'tap':'}'}
keycodes['KC_ASTERISK']={'tap':'*'}
keycodes['KC_TILDE']={'tap':'~'}
keycodes['KC_PLUS']={'tap':'+'}
keycodes['KC_AMPERSAND']={'tap':'&'}
keycodes['KC_PIPE']={'tap':'|'}
keycodes['KC_QUES']={'tap':'?'}
keycodes['KC_QUESTION']={'tap':'?'}
keycodes['KC_DQT']={'tap':'"'}
keycodes['KC_HASH']={'tap':'#'}
keycodes['KC_DOUBLE_QUOTE']={'tap':'"'}
keycodes['KC_COLN']={'tap':':'}
keycodes['KC_COLON']={'tap':':'}

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
unicode={}
tap_dance_used={}
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
                func=re.sub('FLOW|ALL',"",func)
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
            elif m:=re.search(r'MOD_MASK_SHIFT, ([^,]+),\s*(.+)\),$',line):
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
            tap_dance_used[m[1]] = 1
            for tdVariant in td:
                layouts[layout][tdVariant][i]=td[tdVariant]
                processKey(layout, tdVariant, i, False)
        elif m:=re.search('C\((.*)\)',keycode):
            layouts[layout][variant][i]=m[1]
            processKey(layout,variant,i,initial)
            layouts[layout][variant][i]='icon/control.svg'+layouts[layout][variant][i]
        elif re.search('[A-Z]_[A-Z0-9]',keycode):
            layouts[layout][variant][i]=re.sub('_',' ',keycode.lower())
        elif keycode == 'XXXXXXX' or keycode == '_______':
            layouts[layout][variant][i]=''

for layout in layouts:
    for variant in layouts[layout]:
        for i in range(0,len(layouts[layout][variant])):
            processKey(layout, variant, i, True)

def isLayoutEmpty(layout):
    for i in range(0,len(layout)):
        if layout[i]:
            return False
    return True

svgp=[
    {"x": 0, "y": 200, "width": 1500, "height": 1000},
    {"x": 1500, "y": 200, "width": 1000, "height": 1000},
    {"x": 2500, "y": 100, "width": 1000, "height": 1000},
    {"x": 3500, "y": 0, "width": 1000, "height": 1000},
    {"x": 4500, "y": 100, "width": 1000, "height": 1000},
    {"x": 5500, "y": 200, "width": 1000, "height": 1000},
    {"x": 6500, "y": 200, "width": 1000, "height": 1000},
    {"x": 10500, "y": 200, "width": 1000, "height": 1000},
    {"x": 11500, "y": 200, "width": 1000, "height": 1000},
    {"x": 12500, "y": 100, "width": 1000, "height": 1000},
    {"x": 13500, "y": 0, "width": 1000, "height": 1000},
    {"x": 14500, "y": 100, "width": 1000, "height": 1000},
    {"x": 15500, "y": 200, "width": 1000, "height": 1000},
    {"x": 16500, "y": 200, "width": 1500, "height": 1000},

    {"x": 0, "y": 1200, "width": 1500, "height": 1000},
    {"x": 1500, "y": 1200, "width": 1000, "height": 1000},
    {"x": 2500, "y": 1100, "width": 1000, "height": 1000},
    {"x": 3500, "y": 1000, "width": 1000, "height": 1000},
    {"x": 4500, "y": 1100, "width": 1000, "height": 1000},
    {"x": 5500, "y": 1200, "width": 1000, "height": 1000},
    {"x": 6500, "y": 1200, "width": 1000, "height": 1500},
    {"x": 10500, "y": 1200, "width": 1000, "height": 1500},
    {"x": 11500, "y": 1200, "width": 1000, "height": 1000},
    {"x": 12500, "y": 1100, "width": 1000, "height": 1000},
    {"x": 13500, "y": 1000, "width": 1000, "height": 1000},
    {"x": 14500, "y": 1100, "width": 1000, "height": 1000},
    {"x": 15500, "y": 1200, "width": 1000, "height": 1000},
    {"x": 16500, "y": 1200, "width": 1500, "height": 1000},

    {"x": 0, "y": 2200, "width": 1500, "height": 1000},
    {"x": 1500, "y": 2200, "width": 1000, "height": 1000},
    {"x": 2500, "y": 2100, "width": 1000, "height": 1000},
    {"x": 3500, "y": 2000, "width": 1000, "height": 1000},
    {"x": 4500, "y": 2100, "width": 1000, "height": 1000},
    {"x": 5500, "y": 2200, "width": 1000, "height": 1000},
    {"x": 11500, "y": 2200, "width": 1000, "height": 1000},
    {"x": 12500, "y": 2100, "width": 1000, "height": 1000},
    {"x": 13500, "y": 2000, "width": 1000, "height": 1000},
    {"x": 14500, "y": 2100, "width": 1000, "height": 1000},
    {"x": 15500, "y": 2200, "width": 1000, "height": 1000},
    {"x": 16500, "y": 2200, "width": 1500, "height": 1000},

    {"x": 0, "y": 3200, "width": 1500, "height": 1000},
    {"x": 1500, "y": 3200, "width": 1000, "height": 1000},
    {"x": 2500, "y": 3100, "width": 1000, "height": 1000},
    {"x": 3500, "y": 3000, "width": 1000, "height": 1000},
    {"x": 4500, "y": 3100, "width": 1000, "height": 1000},
    {"x": 5500, "y": 3200, "width": 1000, "height": 1000},
    {"x": 6500, "y": 2700, "width": 1000, "height": 1500},
    {"x": 10500, "y": 2700, "width": 1000, "height": 1500},
    {"x": 11500, "y": 3200, "width": 1000, "height": 1000},
    {"x": 12500, "y": 3100, "width": 1000, "height": 1000},
    {"x": 13500, "y": 3000, "width": 1000, "height": 1000},
    {"x": 14500, "y": 3100, "width": 1000, "height": 1000},
    {"x": 15500, "y": 3200, "width": 1000, "height": 1000},
    {"x": 16500, "y": 3200, "width": 1500, "height": 1000},

    {"x": 500, "y": 4200, "width": 1000, "height": 1000},
    {"x": 1500, "y": 4200, "width": 1000, "height": 1000},
    {"x": 2500, "y": 4100, "width": 1000, "height": 1000},
    {"x": 3500, "y": 4000, "width": 1000, "height": 1000},
    {"x": 4500, "y": 4100, "width": 1000, "height": 1000},
    {"x": 12500, "y": 4100, "width": 1000, "height": 1000},
    {"x": 13500, "y": 4000, "width": 1000, "height": 1000},
    {"x": 14500, "y": 4100, "width": 1000, "height": 1000},
    {"x": 15500, "y": 4200, "width": 1000, "height": 1000},
    {"x": 16500, "y": 4200, "width": 1000, "height": 1000},

    {"x": 6750, "y": 4500, "width": 1000, "height": 1000},
    {"x": 7750, "y": 4500, "width": 1000, "height": 1000},
    {"x": 9250, "y": 4500, "width": 1000, "height": 1000},
    {"x": 10250, "y": 4500, "width": 1000, "height": 1000},

    {"x": 7750, "y": 5500, "width": 1000, "height": 1000},
    {"x": 9250, "y": 5500, "width": 1000, "height": 1000},

    {"x": 5750, "y": 5500, "width": 1000, "height": 2000},
    {"x": 6750, "y": 5500, "width": 1000, "height": 2000},
    {"x": 7750, "y": 6500, "width": 1000, "height": 1000},
    {"x": 9250, "y": 6500, "width": 1000, "height": 1000},
    {"x": 10250, "y": 5500, "width": 1000, "height": 2000},
    {"x": 11250, "y": 5500, "width": 1000, "height": 2000},
]

def toSvg(layout, variant):
    svgName=re.sub('_','-',f"layers/{layout}-{variant}.svg")
    fh = open(svgName, 'w')
    fh.write('<?xml version="1.0" encoding="UTF-8" standalone="no"?>\n')
    fh.write('<svg width="900mm" height="375mm" viewBox="0 0 18000 7500" version="1.1" xmlns="http://www.w3.org/2000/svg" xmlns:svg="http://www.w3.org/2000/svg">\n')
    fh.write('<style>\n')
    fh.write('rect{fill:none;stroke:#000;stroke-width:10}\n')
    fh.write('text{font:bold 700px sans-serif;dominant-baseline:middle;text-anchor:middle}\n')
    fh.write('text.medium{font:bold 450px sans-serif;}\n')
    fh.write('text.small{font:bold 200px sans-serif;}\n')
    fh.write('</style>\n')

    l=layouts[layout][variant]
    for i in range(0,min(len(l),len(svgp))):
        content=''
        text = l[i]
        k = svgp[i]
        if re.search(r"^icon/[^/]+\.svg$", text):
            with open(text, "rb") as image_file:
                imgType = re.sub('svg','svg+xml',re.sub(r'.*\.','',text))
                imgB64 = base64.b64encode(image_file.read()).decode('utf-8')
                content = f'<image x="{k['x']+round(k['width']/2)-350}" y="{k['y']+round(k['height']/2)-350}" width="700" height="700" href="data:image/{imgType};base64,{imgB64}"/>'
        else:
            textClass='big'
            if len(text) > 2:
                textClass='medium'
            if len(text) > 5:
                textClass='small'
            if len(text) > 7:
                text = text[:6]+"…"
            content = f'<text class="{textClass}" x="{k['x']+round(k['width']/2)}" y="{k['y']+round(k['height']/2)}">{html.escape(text)}</text>'
        fh.write(f'<rect width="{k['width']-10}" height="{k['height']-10}" x="{k['x']+5}" y="{k['y']+5}" ry="100"/>\n')
        fh.write(f'<rect width="{k['width']-210}" height="{k['height']-210}" x="{k['x']+105}" y="{k['y']+105}" ry="100"/>\n')
        fh.write(content+'\n')
    fh.write('</svg>')
    fh.close()
    return svgName

for layout in layouts:
    for variant in layouts[layout]:
        if not isLayoutEmpty(layouts[layout][variant]):
            svgName = toSvg(layout, variant)
            layoutName = re.sub('_',' ',layout).title()
            variantName = '';
            if variant == 'hold':
                variantName = '(Hold)'
            elif variant == 'dtap':
                variantName = '(Double Tap)'
            elif variant == 'dhold':
                variantName = '(Double Hold)'
            elif variant == 'ttap':
                variantName = '(Triple Tap)'
            elif variant == 'thold':
                variantName = '(Triple Hold)'
            elif variant == 'shift':
                variantName = '(Shift)'

            print(f"### {layoutName} {variantName}")
            print(f"![]({svgName})")

keycap_priority = [
    {"layout": "dvorak", "variant": "tap", "dark-mode": "#fff", "light-mode": "#000"},
    {"layout": "qwerty", "variant": "tap", "dark-mode": "#aaa", "light-mode": "#888"},
    {"layout": "dvorak", "variant": "hold", "dark-mode": "#0ff", "light-mode": "#00c"},
    {"layout": "dvorak", "variant": "dtap", "dark-mode": "#8f8", "light-mode": "#090"},
    {"layout": "num_fn", "variant": "tap", "dark-mode": "#ff0", "light-mode": "#088"},
    {"layout": "dvorak", "variant": "dhold", "dark-mode": "#88f", "light-mode": "#880"},
    {"layout": "dvorak", "variant": "ttap", "dark-mode": "#f0f", "light-mode": "#808"},
    {"layout": "num_fn", "variant": "hold", "dark-mode": "#f88", "light-mode": "#a00"},
]

def getKeycapLabels(i, colorMode):
    labels = []
    seen = {}
    for p in keycap_priority:
        text = layouts[p["layout"]][p["variant"]][i]
        if re.search(r'^[a-z]$', text):
            text = text.upper()
        text = re.sub("-qwerty","",text)
        if text and len(labels) < 4 and text not in seen:
            labels.append({"text":text, "color": p[colorMode]})
            seen[text] = 1
    return labels

def labelsToSvg(fh, labels, dim):
    for i, label in enumerate(labels):
        text = label['text']
        color = label['color']
        textClass='big'
        x = dim['x']
        y = dim['y']
        w = dim['w']
        h = dim['h']
        x+=0.05
        y+=0.05
        w-=0.1
        h-=0.1

        if w > h:
            x += round((w-h) / 2, 3)
            w = h
        elif w < h:
            y += round((h-w) / 2, 3)
            h = w

        if text.startswith("icon/"):
            if len(labels) > 1:
                w =  round(w/2-0.025, 3)
                h =  round(h/2-0.025, 3)
            if i%2 == 1:
                x += w + 0.05
            if i > 1:
                y += h + 0.05
            with open(text, "r") as image_file:
                imgType = re.sub('svg','svg+xml',re.sub(r'.*\.','',text))
                content = ''.join(image_file.readlines())
                content = re.sub(r'#010101', color, content)
                imgB64 = base64.b64encode(content.encode('utf-8')).decode('utf-8')
                fh.write(f'<image x="{x}in" y="{y}in" width="{w}in" height="{h}in" href="data:image/{imgType};base64,{imgB64}"/>\n');
        else:
            if len(labels) == 1:
                if len(text) > 2:
                    textClass='medium'
                if len(text) > 5:
                    textClass='small'
                x = round(x + w/2, 3)
                y = round(y + h/2, 3)
            else:
                textClass='medium'
                if len(text) > 2:
                    textClass='small'
                if i%2 == 0:
                    x = round(x + w/4, 3)
                else:
                    x = round(x + 3*w/4, 3)
                if i < 2:
                    y = round(y + h/4, 3)
                else:
                    y = round(y + 3*h/4, 3)
            fh.write(f'<text fill="{color}" class="{textClass}" x="{x}in" y="{y}in">{html.escape(text)}</text>\n');

def writeKeycapsSvg(fileName, colorMode):
    fh = open(fileName, 'w')
    fh.write('<?xml version="1.0" encoding="UTF-8" standalone="no"?>\n')
    fh.write('<svg width="9.428in" height="4.202in" version="1.1" xmlns="http://www.w3.org/2000/svg" xmlns:svg="http://www.w3.org/2000/svg">\n')
    fh.write('<style>\n')
    if colorMode == "dark-mode":
        fh.write('rect{fill:#000;stroke:none}\n')
    else:
        fh.write('rect{fill:none;stroke:#666;stroke-width:0.01in;stroke-dasharray:1,4}\n')
    fh.write('text{font:bold .4in sans-serif;dominant-baseline:middle;text-anchor:middle}\n')
    fh.write('text.medium{font:bold .16in sans-serif;}\n')
    fh.write('text.small{font:bold .08in sans-serif;}\n')
    fh.write('</style>\n')
    for i, k in enumerate(svgp):
        dim = {
            "w": round(k['width'] * .000452, 3),
            "h": round(k['height'] * .000452, 3),
            "x": round(0.25 + k['x'] * .0005, 3),
            "y": round(0.25 + k['y'] * .0005, 3),
        }
        fh.write(f'<rect width="{dim["w"]}in" height="{dim["h"]}in" x="{dim["x"]}in" y="{dim["y"]}in"/>\n')
        labelsToSvg(fh, getKeycapLabels(i, colorMode), dim);
    fh.write('</svg>')
    fh.close()

writeKeycapsSvg('keycaps-black.svg', 'dark-mode')
writeKeycapsSvg('keycaps-white.svg', 'light-mode')

for c in unicode:
    if c not in unicode_used:
        print(f"not used: {c} {unicode[c]}", file=sys.stderr)

for c in tapdances:
    if c not in tap_dance_used:
        print(f"not used: {c} {tapdances[c]}", file=sys.stderr)
