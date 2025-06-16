# Dvorak-Qwerty Layout for the ErgoDox EZ Keyboard

### [Download the firmware](https://github.com/stephenostermiller/qmk_userspace/releases/download/latest/ergodox_ez_base_dvorak_qwerty.hex)

## Features

### Dvorak-Qwerty

Dvorak layout for faster and more accurate typing. Switches to Qwerty layout when ctrl, meta, or alt are pressed so that cut, copy, and paste are easier to use.

### Space Cadet

Extended space cadet functionality where tapping the shift, ctrl, meta, and alt keys type paired symbols on the lift and right hands. Holding the key causes it to work as a modifier like usual.

### Auto shift

Holding keys types the shifted version of that key.

### Tap Dance

Many key have dual functions and produce different results when tapped, held, double tapped, or even triple tapped.

### Unicode and Emojis

Several keys type unicode symbols. How unicode characters are sent is auto-configured based on the OS of the computer into which the keyboard is plugged.

### Indicator Lights

During keyboard boot, the lights flash blue, green and red in turn.

When the keyboard detects it is connected to a new computer, the lights flash to indicate the detected computer OS:

- Green: Linux
- Red: Mac
- Red and Green: Windows

At other times the lights indicate the layout:

- No lights: Dvorak
- Green light: Qwerty
- Red light: Number keypad
- Blue light: CAPS lock, CAPS word, or arrow lock

### Media keys

Easy access to media keys in the main layout

## Layouts

<style>
.layout{line-height:1.1;font-size:3vw;width:100%;aspect-ratio:2.692;position:relative;background:center/cover url('../../../ergodox_ez.svg')}
.layout .key{position:absolute;transform:translate(-50%,-50%)}
.layout .key img{max-width:3vw}
.layout .lthb{transform:rotate(24deg) translate(-50%,-50%)}
.layout .rthb{transform:rotate(-24deg) translate(-50%,-50%)}
</style>
### dvorak tap
<div class=layout>
<div class="key lhnd" style="top:10.5%;left:4%;font-size:30.0%"><img src=icon/mute-mic.png></div>
<div class="key lhnd" style="top:9.9%;left:10.5%">1</div>
<div class="key lhnd" style="top:7.5%;left:15.6%">2</div>
<div class="key lhnd" style="top:6.5%;left:20.7%">3</div>
<div class="key lhnd" style="top:7.8%;left:25.7%">4</div>
<div class="key lhnd" style="top:8.5%;left:30.8%">5</div>
<div class="key lhnd" style="top:8.5%;left:36%;font-size:30.0%"><img src=icon/play-pause.png></div>
<div class="key rhnd" style="top:8.5%;left:63.9%;font-size:30.0%"><img src=icon/calculator.png></div>
<div class="key rhnd" style="top:8.5%;left:69.3%">6</div>
<div class="key rhnd" style="top:7.8%;left:74%">7</div>
<div class="key rhnd" style="top:6.5%;left:79.3%">8</div>
<div class="key rhnd" style="top:7.5%;left:84.4%">9</div>
<div class="key rhnd" style="top:9.9%;left:89.6%">0</div>
<div class="key rhnd" style="top:10.5%;left:96%">\</div>
<div class="key lhnd" style="top:24.4%;left:4%;font-size:30.0%"><img src=icon/volume-up.png></div>
<div class="key lhnd" style="top:23.8%;left:10.5%">"</div>
<div class="key lhnd" style="top:21.4%;left:15.6%">,</div>
<div class="key lhnd" style="top:20.4%;left:20.7%">.</div>
<div class="key lhnd" style="top:20.8%;left:25.7%">p</div>
<div class="key lhnd" style="top:21.5%;left:30.8%">y</div>
<div class="key lhnd" style="top:25.5%;left:36%;font-size:30.0%"><img src=icon/next-track.png></div>
<div class="key rhnd" style="top:25.5%;left:63.9%">=</div>
<div class="key rhnd" style="top:22.7%;left:69.3%">f</div>
<div class="key rhnd" style="top:20.8%;left:74%">g</div>
<div class="key rhnd" style="top:20.4%;left:79.3%">c</div>
<div class="key rhnd" style="top:21.4%;left:84.4%">r</div>
<div class="key rhnd" style="top:23.8%;left:89.6%">l</div>
<div class="key rhnd" style="top:24.4%;left:96%">/</div>
<div class="key lhnd" style="top:37.5%;left:4%;font-size:30.0%"><img src=icon/volume-down.png></div>
<div class="key lhnd" style="top:38.8%;left:10.5%">a</div>
<div class="key lhnd" style="top:36.4%;left:15.6%">o</div>
<div class="key lhnd" style="top:35.4%;left:20.7%">e</div>
<div class="key lhnd" style="top:35.8%;left:25.7%">u</div>
<div class="key lhnd" style="top:36.5%;left:30.8%">i</div>
<div class="key rhnd" style="top:37.7%;left:69.3%">d</div>
<div class="key rhnd" style="top:35.8%;left:74%">h</div>
<div class="key rhnd" style="top:35.4%;left:79.3%">t</div>
<div class="key rhnd" style="top:36.4%;left:84.4%">n</div>
<div class="key rhnd" style="top:38.8%;left:89.6%">s</div>
<div class="key rhnd" style="top:37.5%;left:96%">-</div>
<div class="key lhnd" style="top:51%;left:4%">(</div>
<div class="key lhnd" style="top:51%;left:10.5%">;</div>
<div class="key lhnd" style="top:49%;left:15.6%">q</div>
<div class="key lhnd" style="top:48%;left:20.7%">j</div>
<div class="key lhnd" style="top:49%;left:25.7%">k</div>
<div class="key lhnd" style="top:50%;left:30.8%">x</div>
<div class="key lhnd" style="top:47%;left:36%;font-size:30.0%"><img src=icon/previous-track.png></div>
<div class="key rhnd" style="top:47%;left:63.9%">`</div>
<div class="key rhnd" style="top:50%;left:69.3%">b</div>
<div class="key rhnd" style="top:49%;left:74%">m</div>
<div class="key rhnd" style="top:48%;left:79.3%">w</div>
<div class="key rhnd" style="top:49%;left:84.4%">v</div>
<div class="key rhnd" style="top:51%;left:89.6%">z</div>
<div class="key rhnd" style="top:51%;left:96%">)</div>
<div class="key lhnd" style="top:65%;left:5%;font-size:30.0%"><img src=icon/screenshot.png></div>
<div class="key lhnd" style="top:65%;left:10.5%;font-size:30.0%"><img src=icon/keypad.png></div>
<div class="key lhnd" style="top:63%;left:15.6%"><</div>
<div class="key lhnd" style="top:62%;left:20.7%">[</div>
<div class="key lhnd" style="top:63%;left:25.7%">{</div>
<div class="key rhnd" style="top:63%;left:74%">}</div>
<div class="key rhnd" style="top:62%;left:79.3%">]</div>
<div class="key rhnd" style="top:63%;left:84.4%">></div>
<div class="key rhnd" style="top:65%;left:89.6%;font-size:30.0%"><img src=icon/page-up.png></div>
<div class="key rhnd" style="top:65%;left:95%;font-size:30.0%"><img src=icon/page-down.png></div>
<div class="key lthb" style="top:62%;left:41%;font-size:30.0%"><img src=icon/home.png></div>
<div class="key lthb" style="top:68.6%;left:45.2%;font-size:30.0%"><img src=icon/end.png></div>
<div class="key rthb" style="top:65%;left:54.8%;font-size:30.0%"><img src=icon/escape.png></div>
<div class="key rthb" style="top:58.2%;left:59%;font-size:30.0%"><img src=icon/delete.png></div>
<div class="key lthb" style="top:80.2%;left:43.3%">⇨</div>
<div class="key rthb" style="top:77%;left:56.7%">⇧</div>
<div class="key lthb" style="top:73%;left:33.5%;font-size:30.0%"><img src=icon/enter.png></div>
<div class="key lthb" style="top:79%;left:38%;font-size:30.0%"><img src=icon/tab.png></div>
<div class="key lthb" style="top:92.6%;left:41.5%">⇦</div>
<div class="key rthb" style="top:89.4%;left:58.6%">⇩</div>
<div class="key rthb" style="top:77%;left:62%;font-size:30.0%"><img src=icon/backspace.png></div>
<div class="key rthb" style="top:71%;left:66.8%;font-size:30.0%"><img src=icon/space.png></div>
</div>

### dvorak hold
<div class=layout>
<div class="key lhnd" style="top:10.5%;left:4%"></div>
<div class="key lhnd" style="top:9.9%;left:10.5%">!</div>
<div class="key lhnd" style="top:7.5%;left:15.6%">@</div>
<div class="key lhnd" style="top:6.5%;left:20.7%">#</div>
<div class="key lhnd" style="top:7.8%;left:25.7%">$</div>
<div class="key lhnd" style="top:8.5%;left:30.8%">%</div>
<div class="key lhnd" style="top:8.5%;left:36%"></div>
<div class="key rhnd" style="top:8.5%;left:63.9%"></div>
<div class="key rhnd" style="top:8.5%;left:69.3%">^</div>
<div class="key rhnd" style="top:7.8%;left:74%">&</div>
<div class="key rhnd" style="top:6.5%;left:79.3%">*</div>
<div class="key rhnd" style="top:7.5%;left:84.4%">★</div>
<div class="key rhnd" style="top:9.9%;left:89.6%">☆</div>
<div class="key rhnd" style="top:10.5%;left:96%">|</div>
<div class="key lhnd" style="top:24.4%;left:4%"></div>
<div class="key lhnd" style="top:23.8%;left:10.5%">'</div>
<div class="key lhnd" style="top:21.4%;left:15.6%">≤</div>
<div class="key lhnd" style="top:20.4%;left:20.7%">≥</div>
<div class="key lhnd" style="top:20.8%;left:25.7%">P</div>
<div class="key lhnd" style="top:21.5%;left:30.8%">Y</div>
<div class="key lhnd" style="top:25.5%;left:36%;font-size:30.0%"><img src=icon/fast-forward.png></div>
<div class="key rhnd" style="top:25.5%;left:63.9%">+</div>
<div class="key rhnd" style="top:22.7%;left:69.3%">F</div>
<div class="key rhnd" style="top:20.8%;left:74%">G</div>
<div class="key rhnd" style="top:20.4%;left:79.3%">C</div>
<div class="key rhnd" style="top:21.4%;left:84.4%">R</div>
<div class="key rhnd" style="top:23.8%;left:89.6%">L</div>
<div class="key rhnd" style="top:24.4%;left:96%">?</div>
<div class="key lhnd" style="top:37.5%;left:4%"></div>
<div class="key lhnd" style="top:38.8%;left:10.5%">A</div>
<div class="key lhnd" style="top:36.4%;left:15.6%">O</div>
<div class="key lhnd" style="top:35.4%;left:20.7%">E</div>
<div class="key lhnd" style="top:35.8%;left:25.7%">U</div>
<div class="key lhnd" style="top:36.5%;left:30.8%">I</div>
<div class="key rhnd" style="top:37.7%;left:69.3%">D</div>
<div class="key rhnd" style="top:35.8%;left:74%">H</div>
<div class="key rhnd" style="top:35.4%;left:79.3%">T</div>
<div class="key rhnd" style="top:36.4%;left:84.4%">N</div>
<div class="key rhnd" style="top:38.8%;left:89.6%">S</div>
<div class="key rhnd" style="top:37.5%;left:96%">_</div>
<div class="key lhnd" style="top:51%;left:4%;font-size:30.0%"><img src=icon/shift.png></div>
<div class="key lhnd" style="top:51%;left:10.5%">:</div>
<div class="key lhnd" style="top:49%;left:15.6%">Q</div>
<div class="key lhnd" style="top:48%;left:20.7%">J</div>
<div class="key lhnd" style="top:49%;left:25.7%">K</div>
<div class="key lhnd" style="top:50%;left:30.8%">X</div>
<div class="key lhnd" style="top:47%;left:36%;font-size:30.0%"><img src=icon/rewind.png></div>
<div class="key rhnd" style="top:47%;left:63.9%">~</div>
<div class="key rhnd" style="top:50%;left:69.3%">B</div>
<div class="key rhnd" style="top:49%;left:74%">M</div>
<div class="key rhnd" style="top:48%;left:79.3%">W</div>
<div class="key rhnd" style="top:49%;left:84.4%">V</div>
<div class="key rhnd" style="top:51%;left:89.6%">Z</div>
<div class="key rhnd" style="top:51%;left:96%;font-size:30.0%"><img src=icon/shift.png></div>
<div class="key lhnd" style="top:65%;left:5%"></div>
<div class="key lhnd" style="top:65%;left:10.5%;font-size:30.0%"><img src=icon/keypad.png></div>
<div class="key lhnd" style="top:63%;left:15.6%;font-size:30.0%">ctrl<br>qwerty</div>
<div class="key lhnd" style="top:62%;left:20.7%;font-size:30.0%">meta<br>qwerty</div>
<div class="key lhnd" style="top:63%;left:25.7%;font-size:30.0%">alt<br>qwerty</div>
<div class="key rhnd" style="top:63%;left:74%;font-size:30.0%">alt<br>qwerty</div>
<div class="key rhnd" style="top:62%;left:79.3%;font-size:30.0%">meta<br>qwerty</div>
<div class="key rhnd" style="top:63%;left:84.4%;font-size:30.0%">ctrl<br>qwerty</div>
<div class="key rhnd" style="top:65%;left:89.6%"></div>
<div class="key rhnd" style="top:65%;left:95%"></div>
<div class="key lthb" style="top:62%;left:41%"></div>
<div class="key lthb" style="top:68.6%;left:45.2%"></div>
<div class="key rthb" style="top:65%;left:54.8%"></div>
<div class="key rthb" style="top:58.2%;left:59%"></div>
<div class="key lthb" style="top:80.2%;left:43.3%"></div>
<div class="key rthb" style="top:77%;left:56.7%"></div>
<div class="key lthb" style="top:73%;left:33.5%"></div>
<div class="key lthb" style="top:79%;left:38%"></div>
<div class="key lthb" style="top:92.6%;left:41.5%"></div>
<div class="key rthb" style="top:89.4%;left:58.6%"></div>
<div class="key rthb" style="top:77%;left:62%"></div>
<div class="key rthb" style="top:71%;left:66.8%"></div>
</div>

### dvorak shift
<div class=layout>
<div class="key lhnd" style="top:10.5%;left:4%">☐</div>
<div class="key lhnd" style="top:9.9%;left:10.5%">!</div>
<div class="key lhnd" style="top:7.5%;left:15.6%">@</div>
<div class="key lhnd" style="top:6.5%;left:20.7%">#</div>
<div class="key lhnd" style="top:7.8%;left:25.7%">$</div>
<div class="key lhnd" style="top:8.5%;left:30.8%">%</div>
<div class="key lhnd" style="top:8.5%;left:36%">—</div>
<div class="key rhnd" style="top:8.5%;left:63.9%"></div>
<div class="key rhnd" style="top:8.5%;left:69.3%">^</div>
<div class="key rhnd" style="top:7.8%;left:74%">&</div>
<div class="key rhnd" style="top:6.5%;left:79.3%">*</div>
<div class="key rhnd" style="top:7.5%;left:84.4%">★</div>
<div class="key rhnd" style="top:9.9%;left:89.6%">☆</div>
<div class="key rhnd" style="top:10.5%;left:96%">|</div>
<div class="key lhnd" style="top:24.4%;left:4%">☑</div>
<div class="key lhnd" style="top:23.8%;left:10.5%">'</div>
<div class="key lhnd" style="top:21.4%;left:15.6%">≤</div>
<div class="key lhnd" style="top:20.4%;left:20.7%">≥</div>
<div class="key lhnd" style="top:20.8%;left:25.7%">P</div>
<div class="key lhnd" style="top:21.5%;left:30.8%">Y</div>
<div class="key lhnd" style="top:25.5%;left:36%">↑</div>
<div class="key rhnd" style="top:25.5%;left:63.9%">+</div>
<div class="key rhnd" style="top:22.7%;left:69.3%">F</div>
<div class="key rhnd" style="top:20.8%;left:74%">G</div>
<div class="key rhnd" style="top:20.4%;left:79.3%">C</div>
<div class="key rhnd" style="top:21.4%;left:84.4%">R</div>
<div class="key rhnd" style="top:23.8%;left:89.6%">L</div>
<div class="key rhnd" style="top:24.4%;left:96%">?</div>
<div class="key lhnd" style="top:37.5%;left:4%">☒</div>
<div class="key lhnd" style="top:38.8%;left:10.5%">A</div>
<div class="key lhnd" style="top:36.4%;left:15.6%">O</div>
<div class="key lhnd" style="top:35.4%;left:20.7%">E</div>
<div class="key lhnd" style="top:35.8%;left:25.7%">U</div>
<div class="key lhnd" style="top:36.5%;left:30.8%">I</div>
<div class="key rhnd" style="top:37.7%;left:69.3%">D</div>
<div class="key rhnd" style="top:35.8%;left:74%">H</div>
<div class="key rhnd" style="top:35.4%;left:79.3%">T</div>
<div class="key rhnd" style="top:36.4%;left:84.4%">N</div>
<div class="key rhnd" style="top:38.8%;left:89.6%">S</div>
<div class="key rhnd" style="top:37.5%;left:96%">_</div>
<div class="key lhnd" style="top:51%;left:4%"></div>
<div class="key lhnd" style="top:51%;left:10.5%">:</div>
<div class="key lhnd" style="top:49%;left:15.6%">Q</div>
<div class="key lhnd" style="top:48%;left:20.7%">J</div>
<div class="key lhnd" style="top:49%;left:25.7%">K</div>
<div class="key lhnd" style="top:50%;left:30.8%">X</div>
<div class="key lhnd" style="top:47%;left:36%">↓</div>
<div class="key rhnd" style="top:47%;left:63.9%">~</div>
<div class="key rhnd" style="top:50%;left:69.3%">B</div>
<div class="key rhnd" style="top:49%;left:74%">M</div>
<div class="key rhnd" style="top:48%;left:79.3%">W</div>
<div class="key rhnd" style="top:49%;left:84.4%">V</div>
<div class="key rhnd" style="top:51%;left:89.6%">Z</div>
<div class="key rhnd" style="top:51%;left:96%"></div>
<div class="key lhnd" style="top:65%;left:5%">👍</div>
<div class="key lhnd" style="top:65%;left:10.5%">👎</div>
<div class="key lhnd" style="top:63%;left:15.6%"></div>
<div class="key lhnd" style="top:62%;left:20.7%"></div>
<div class="key lhnd" style="top:63%;left:25.7%"></div>
<div class="key rhnd" style="top:63%;left:74%"></div>
<div class="key rhnd" style="top:62%;left:79.3%"></div>
<div class="key rhnd" style="top:63%;left:84.4%"></div>
<div class="key rhnd" style="top:65%;left:89.6%"></div>
<div class="key rhnd" style="top:65%;left:95%"></div>
<div class="key lthb" style="top:62%;left:41%"></div>
<div class="key lthb" style="top:68.6%;left:45.2%"></div>
<div class="key rthb" style="top:65%;left:54.8%"></div>
<div class="key rthb" style="top:58.2%;left:59%"></div>
<div class="key lthb" style="top:80.2%;left:43.3%"></div>
<div class="key rthb" style="top:77%;left:56.7%"></div>
<div class="key lthb" style="top:73%;left:33.5%"></div>
<div class="key lthb" style="top:79%;left:38%"></div>
<div class="key lthb" style="top:92.6%;left:41.5%"></div>
<div class="key rthb" style="top:89.4%;left:58.6%"></div>
<div class="key rthb" style="top:77%;left:62%"></div>
<div class="key rthb" style="top:71%;left:66.8%"></div>
</div>

### dvorak dtap
<div class=layout>
<div class="key lhnd" style="top:10.5%;left:4%;font-size:30.0%"><img src=icon/camera-off.png></div>
<div class="key lhnd" style="top:9.9%;left:10.5%"></div>
<div class="key lhnd" style="top:7.5%;left:15.6%"></div>
<div class="key lhnd" style="top:6.5%;left:20.7%"></div>
<div class="key lhnd" style="top:7.8%;left:25.7%"></div>
<div class="key lhnd" style="top:8.5%;left:30.8%"></div>
<div class="key lhnd" style="top:8.5%;left:36%;font-size:30.0%"><img src=icon/media-player.png></div>
<div class="key rhnd" style="top:8.5%;left:63.9%;font-size:30.0%"><img src=icon/mail.png></div>
<div class="key rhnd" style="top:8.5%;left:69.3%"></div>
<div class="key rhnd" style="top:7.8%;left:74%"></div>
<div class="key rhnd" style="top:6.5%;left:79.3%"></div>
<div class="key rhnd" style="top:7.5%;left:84.4%"></div>
<div class="key rhnd" style="top:9.9%;left:89.6%"></div>
<div class="key rhnd" style="top:10.5%;left:96%"></div>
<div class="key lhnd" style="top:24.4%;left:4%"></div>
<div class="key lhnd" style="top:23.8%;left:10.5%"></div>
<div class="key lhnd" style="top:21.4%;left:15.6%"></div>
<div class="key lhnd" style="top:20.4%;left:20.7%"></div>
<div class="key lhnd" style="top:20.8%;left:25.7%"></div>
<div class="key lhnd" style="top:21.5%;left:30.8%"></div>
<div class="key lhnd" style="top:25.5%;left:36%"></div>
<div class="key rhnd" style="top:25.5%;left:63.9%"></div>
<div class="key rhnd" style="top:22.7%;left:69.3%"></div>
<div class="key rhnd" style="top:20.8%;left:74%"></div>
<div class="key rhnd" style="top:20.4%;left:79.3%"></div>
<div class="key rhnd" style="top:21.4%;left:84.4%"></div>
<div class="key rhnd" style="top:23.8%;left:89.6%"></div>
<div class="key rhnd" style="top:24.4%;left:96%"></div>
<div class="key lhnd" style="top:37.5%;left:4%"></div>
<div class="key lhnd" style="top:38.8%;left:10.5%"></div>
<div class="key lhnd" style="top:36.4%;left:15.6%"></div>
<div class="key lhnd" style="top:35.4%;left:20.7%"></div>
<div class="key lhnd" style="top:35.8%;left:25.7%"></div>
<div class="key lhnd" style="top:36.5%;left:30.8%"></div>
<div class="key rhnd" style="top:37.7%;left:69.3%"></div>
<div class="key rhnd" style="top:35.8%;left:74%"></div>
<div class="key rhnd" style="top:35.4%;left:79.3%"></div>
<div class="key rhnd" style="top:36.4%;left:84.4%"></div>
<div class="key rhnd" style="top:38.8%;left:89.6%"></div>
<div class="key rhnd" style="top:37.5%;left:96%"></div>
<div class="key lhnd" style="top:51%;left:4%;font-size:30.0%"><img src=icon/caps-word.png></div>
<div class="key lhnd" style="top:51%;left:10.5%"></div>
<div class="key lhnd" style="top:49%;left:15.6%"></div>
<div class="key lhnd" style="top:48%;left:20.7%"></div>
<div class="key lhnd" style="top:49%;left:25.7%"></div>
<div class="key lhnd" style="top:50%;left:30.8%"></div>
<div class="key lhnd" style="top:47%;left:36%"></div>
<div class="key rhnd" style="top:47%;left:63.9%"></div>
<div class="key rhnd" style="top:50%;left:69.3%"></div>
<div class="key rhnd" style="top:49%;left:74%"></div>
<div class="key rhnd" style="top:48%;left:79.3%"></div>
<div class="key rhnd" style="top:49%;left:84.4%"></div>
<div class="key rhnd" style="top:51%;left:89.6%"></div>
<div class="key rhnd" style="top:51%;left:96%;font-size:30.0%"><img src=icon/caps-lock.png></div>
<div class="key lhnd" style="top:65%;left:5%;font-size:30.0%"><img src=icon/folder.png></div>
<div class="key lhnd" style="top:65%;left:10.5%;font-size:30.0%">qwerty</div>
<div class="key lhnd" style="top:63%;left:15.6%"></div>
<div class="key lhnd" style="top:62%;left:20.7%;font-size:30.0%"><img src=icon/auto-shift.png></div>
<div class="key lhnd" style="top:63%;left:25.7%;font-size:30.0%"><img src=icon/insert.png></div>
<div class="key rhnd" style="top:63%;left:74%;font-size:30.0%"><img src=icon/lock-screen.png></div>
<div class="key rhnd" style="top:62%;left:79.3%;font-size:30.0%"><img src=icon/full-screen.png></div>
<div class="key rhnd" style="top:63%;left:84.4%;font-size:30.0%"><img src=icon/close-window.png></div>
<div class="key rhnd" style="top:65%;left:89.6%"></div>
<div class="key rhnd" style="top:65%;left:95%"></div>
<div class="key lthb" style="top:62%;left:41%;font-size:30.0%"><img src=icon/top.png></div>
<div class="key lthb" style="top:68.6%;left:45.2%;font-size:30.0%"><img src=icon/bottom.png></div>
<div class="key rthb" style="top:65%;left:54.8%"></div>
<div class="key rthb" style="top:58.2%;left:59%"></div>
<div class="key lthb" style="top:80.2%;left:43.3%"></div>
<div class="key rthb" style="top:77%;left:56.7%"></div>
<div class="key lthb" style="top:73%;left:33.5%"></div>
<div class="key lthb" style="top:79%;left:38%"></div>
<div class="key lthb" style="top:92.6%;left:41.5%"></div>
<div class="key rthb" style="top:89.4%;left:58.6%"></div>
<div class="key rthb" style="top:77%;left:62%"></div>
<div class="key rthb" style="top:71%;left:66.8%"></div>
</div>

### dvorak dhold
<div class=layout>
<div class="key lhnd" style="top:10.5%;left:4%"></div>
<div class="key lhnd" style="top:9.9%;left:10.5%"></div>
<div class="key lhnd" style="top:7.5%;left:15.6%"></div>
<div class="key lhnd" style="top:6.5%;left:20.7%"></div>
<div class="key lhnd" style="top:7.8%;left:25.7%"></div>
<div class="key lhnd" style="top:8.5%;left:30.8%"></div>
<div class="key lhnd" style="top:8.5%;left:36%"></div>
<div class="key rhnd" style="top:8.5%;left:63.9%"></div>
<div class="key rhnd" style="top:8.5%;left:69.3%"></div>
<div class="key rhnd" style="top:7.8%;left:74%"></div>
<div class="key rhnd" style="top:6.5%;left:79.3%"></div>
<div class="key rhnd" style="top:7.5%;left:84.4%"></div>
<div class="key rhnd" style="top:9.9%;left:89.6%"></div>
<div class="key rhnd" style="top:10.5%;left:96%"></div>
<div class="key lhnd" style="top:24.4%;left:4%"></div>
<div class="key lhnd" style="top:23.8%;left:10.5%"></div>
<div class="key lhnd" style="top:21.4%;left:15.6%"></div>
<div class="key lhnd" style="top:20.4%;left:20.7%"></div>
<div class="key lhnd" style="top:20.8%;left:25.7%"></div>
<div class="key lhnd" style="top:21.5%;left:30.8%"></div>
<div class="key lhnd" style="top:25.5%;left:36%"></div>
<div class="key rhnd" style="top:25.5%;left:63.9%"></div>
<div class="key rhnd" style="top:22.7%;left:69.3%"></div>
<div class="key rhnd" style="top:20.8%;left:74%"></div>
<div class="key rhnd" style="top:20.4%;left:79.3%"></div>
<div class="key rhnd" style="top:21.4%;left:84.4%"></div>
<div class="key rhnd" style="top:23.8%;left:89.6%"></div>
<div class="key rhnd" style="top:24.4%;left:96%"></div>
<div class="key lhnd" style="top:37.5%;left:4%"></div>
<div class="key lhnd" style="top:38.8%;left:10.5%"></div>
<div class="key lhnd" style="top:36.4%;left:15.6%"></div>
<div class="key lhnd" style="top:35.4%;left:20.7%"></div>
<div class="key lhnd" style="top:35.8%;left:25.7%"></div>
<div class="key lhnd" style="top:36.5%;left:30.8%"></div>
<div class="key rhnd" style="top:37.7%;left:69.3%"></div>
<div class="key rhnd" style="top:35.8%;left:74%"></div>
<div class="key rhnd" style="top:35.4%;left:79.3%"></div>
<div class="key rhnd" style="top:36.4%;left:84.4%"></div>
<div class="key rhnd" style="top:38.8%;left:89.6%"></div>
<div class="key rhnd" style="top:37.5%;left:96%"></div>
<div class="key lhnd" style="top:51%;left:4%"></div>
<div class="key lhnd" style="top:51%;left:10.5%"></div>
<div class="key lhnd" style="top:49%;left:15.6%"></div>
<div class="key lhnd" style="top:48%;left:20.7%"></div>
<div class="key lhnd" style="top:49%;left:25.7%"></div>
<div class="key lhnd" style="top:50%;left:30.8%"></div>
<div class="key lhnd" style="top:47%;left:36%"></div>
<div class="key rhnd" style="top:47%;left:63.9%"></div>
<div class="key rhnd" style="top:50%;left:69.3%"></div>
<div class="key rhnd" style="top:49%;left:74%"></div>
<div class="key rhnd" style="top:48%;left:79.3%"></div>
<div class="key rhnd" style="top:49%;left:84.4%"></div>
<div class="key rhnd" style="top:51%;left:89.6%"></div>
<div class="key rhnd" style="top:51%;left:96%"></div>
<div class="key lhnd" style="top:65%;left:5%"></div>
<div class="key lhnd" style="top:65%;left:10.5%;font-size:30.0%">qwerty</div>
<div class="key lhnd" style="top:63%;left:15.6%"></div>
<div class="key lhnd" style="top:62%;left:20.7%"></div>
<div class="key lhnd" style="top:63%;left:25.7%"></div>
<div class="key rhnd" style="top:63%;left:74%"></div>
<div class="key rhnd" style="top:62%;left:79.3%"></div>
<div class="key rhnd" style="top:63%;left:84.4%"></div>
<div class="key rhnd" style="top:65%;left:89.6%"></div>
<div class="key rhnd" style="top:65%;left:95%"></div>
<div class="key lthb" style="top:62%;left:41%"></div>
<div class="key lthb" style="top:68.6%;left:45.2%"></div>
<div class="key rthb" style="top:65%;left:54.8%"></div>
<div class="key rthb" style="top:58.2%;left:59%"></div>
<div class="key lthb" style="top:80.2%;left:43.3%"></div>
<div class="key rthb" style="top:77%;left:56.7%"></div>
<div class="key lthb" style="top:73%;left:33.5%"></div>
<div class="key lthb" style="top:79%;left:38%"></div>
<div class="key lthb" style="top:92.6%;left:41.5%"></div>
<div class="key rthb" style="top:89.4%;left:58.6%"></div>
<div class="key rthb" style="top:77%;left:62%"></div>
<div class="key rthb" style="top:71%;left:66.8%"></div>
</div>

### dvorak ttap
<div class=layout>
<div class="key lhnd" style="top:10.5%;left:4%;font-size:30.0%">audio<br>mute</div>
<div class="key lhnd" style="top:9.9%;left:10.5%"></div>
<div class="key lhnd" style="top:7.5%;left:15.6%"></div>
<div class="key lhnd" style="top:6.5%;left:20.7%"></div>
<div class="key lhnd" style="top:7.8%;left:25.7%"></div>
<div class="key lhnd" style="top:8.5%;left:30.8%"></div>
<div class="key lhnd" style="top:8.5%;left:36%"></div>
<div class="key rhnd" style="top:8.5%;left:63.9%"></div>
<div class="key rhnd" style="top:8.5%;left:69.3%"></div>
<div class="key rhnd" style="top:7.8%;left:74%"></div>
<div class="key rhnd" style="top:6.5%;left:79.3%"></div>
<div class="key rhnd" style="top:7.5%;left:84.4%"></div>
<div class="key rhnd" style="top:9.9%;left:89.6%"></div>
<div class="key rhnd" style="top:10.5%;left:96%"></div>
<div class="key lhnd" style="top:24.4%;left:4%"></div>
<div class="key lhnd" style="top:23.8%;left:10.5%"></div>
<div class="key lhnd" style="top:21.4%;left:15.6%"></div>
<div class="key lhnd" style="top:20.4%;left:20.7%"></div>
<div class="key lhnd" style="top:20.8%;left:25.7%"></div>
<div class="key lhnd" style="top:21.5%;left:30.8%"></div>
<div class="key lhnd" style="top:25.5%;left:36%"></div>
<div class="key rhnd" style="top:25.5%;left:63.9%"></div>
<div class="key rhnd" style="top:22.7%;left:69.3%"></div>
<div class="key rhnd" style="top:20.8%;left:74%"></div>
<div class="key rhnd" style="top:20.4%;left:79.3%"></div>
<div class="key rhnd" style="top:21.4%;left:84.4%"></div>
<div class="key rhnd" style="top:23.8%;left:89.6%"></div>
<div class="key rhnd" style="top:24.4%;left:96%"></div>
<div class="key lhnd" style="top:37.5%;left:4%"></div>
<div class="key lhnd" style="top:38.8%;left:10.5%"></div>
<div class="key lhnd" style="top:36.4%;left:15.6%"></div>
<div class="key lhnd" style="top:35.4%;left:20.7%"></div>
<div class="key lhnd" style="top:35.8%;left:25.7%"></div>
<div class="key lhnd" style="top:36.5%;left:30.8%"></div>
<div class="key rhnd" style="top:37.7%;left:69.3%"></div>
<div class="key rhnd" style="top:35.8%;left:74%"></div>
<div class="key rhnd" style="top:35.4%;left:79.3%"></div>
<div class="key rhnd" style="top:36.4%;left:84.4%"></div>
<div class="key rhnd" style="top:38.8%;left:89.6%"></div>
<div class="key rhnd" style="top:37.5%;left:96%"></div>
<div class="key lhnd" style="top:51%;left:4%"></div>
<div class="key lhnd" style="top:51%;left:10.5%"></div>
<div class="key lhnd" style="top:49%;left:15.6%"></div>
<div class="key lhnd" style="top:48%;left:20.7%"></div>
<div class="key lhnd" style="top:49%;left:25.7%"></div>
<div class="key lhnd" style="top:50%;left:30.8%"></div>
<div class="key lhnd" style="top:47%;left:36%"></div>
<div class="key rhnd" style="top:47%;left:63.9%"></div>
<div class="key rhnd" style="top:50%;left:69.3%"></div>
<div class="key rhnd" style="top:49%;left:74%"></div>
<div class="key rhnd" style="top:48%;left:79.3%"></div>
<div class="key rhnd" style="top:49%;left:84.4%"></div>
<div class="key rhnd" style="top:51%;left:89.6%"></div>
<div class="key rhnd" style="top:51%;left:96%"></div>
<div class="key lhnd" style="top:65%;left:5%"></div>
<div class="key lhnd" style="top:65%;left:10.5%"></div>
<div class="key lhnd" style="top:63%;left:15.6%"></div>
<div class="key lhnd" style="top:62%;left:20.7%"></div>
<div class="key lhnd" style="top:63%;left:25.7%"></div>
<div class="key rhnd" style="top:63%;left:74%"></div>
<div class="key rhnd" style="top:62%;left:79.3%"></div>
<div class="key rhnd" style="top:63%;left:84.4%"></div>
<div class="key rhnd" style="top:65%;left:89.6%"></div>
<div class="key rhnd" style="top:65%;left:95%"></div>
<div class="key lthb" style="top:62%;left:41%"></div>
<div class="key lthb" style="top:68.6%;left:45.2%"></div>
<div class="key rthb" style="top:65%;left:54.8%"></div>
<div class="key rthb" style="top:58.2%;left:59%"></div>
<div class="key lthb" style="top:80.2%;left:43.3%"></div>
<div class="key rthb" style="top:77%;left:56.7%"></div>
<div class="key lthb" style="top:73%;left:33.5%"></div>
<div class="key lthb" style="top:79%;left:38%"></div>
<div class="key lthb" style="top:92.6%;left:41.5%"></div>
<div class="key rthb" style="top:89.4%;left:58.6%"></div>
<div class="key rthb" style="top:77%;left:62%"></div>
<div class="key rthb" style="top:71%;left:66.8%"></div>
</div>

### dvorak thold
<div class=layout>
<div class="key lhnd" style="top:10.5%;left:4%"></div>
<div class="key lhnd" style="top:9.9%;left:10.5%"></div>
<div class="key lhnd" style="top:7.5%;left:15.6%"></div>
<div class="key lhnd" style="top:6.5%;left:20.7%"></div>
<div class="key lhnd" style="top:7.8%;left:25.7%"></div>
<div class="key lhnd" style="top:8.5%;left:30.8%"></div>
<div class="key lhnd" style="top:8.5%;left:36%"></div>
<div class="key rhnd" style="top:8.5%;left:63.9%"></div>
<div class="key rhnd" style="top:8.5%;left:69.3%"></div>
<div class="key rhnd" style="top:7.8%;left:74%"></div>
<div class="key rhnd" style="top:6.5%;left:79.3%"></div>
<div class="key rhnd" style="top:7.5%;left:84.4%"></div>
<div class="key rhnd" style="top:9.9%;left:89.6%"></div>
<div class="key rhnd" style="top:10.5%;left:96%"></div>
<div class="key lhnd" style="top:24.4%;left:4%"></div>
<div class="key lhnd" style="top:23.8%;left:10.5%"></div>
<div class="key lhnd" style="top:21.4%;left:15.6%"></div>
<div class="key lhnd" style="top:20.4%;left:20.7%"></div>
<div class="key lhnd" style="top:20.8%;left:25.7%"></div>
<div class="key lhnd" style="top:21.5%;left:30.8%"></div>
<div class="key lhnd" style="top:25.5%;left:36%"></div>
<div class="key rhnd" style="top:25.5%;left:63.9%"></div>
<div class="key rhnd" style="top:22.7%;left:69.3%"></div>
<div class="key rhnd" style="top:20.8%;left:74%"></div>
<div class="key rhnd" style="top:20.4%;left:79.3%"></div>
<div class="key rhnd" style="top:21.4%;left:84.4%"></div>
<div class="key rhnd" style="top:23.8%;left:89.6%"></div>
<div class="key rhnd" style="top:24.4%;left:96%"></div>
<div class="key lhnd" style="top:37.5%;left:4%"></div>
<div class="key lhnd" style="top:38.8%;left:10.5%"></div>
<div class="key lhnd" style="top:36.4%;left:15.6%"></div>
<div class="key lhnd" style="top:35.4%;left:20.7%"></div>
<div class="key lhnd" style="top:35.8%;left:25.7%"></div>
<div class="key lhnd" style="top:36.5%;left:30.8%"></div>
<div class="key rhnd" style="top:37.7%;left:69.3%"></div>
<div class="key rhnd" style="top:35.8%;left:74%"></div>
<div class="key rhnd" style="top:35.4%;left:79.3%"></div>
<div class="key rhnd" style="top:36.4%;left:84.4%"></div>
<div class="key rhnd" style="top:38.8%;left:89.6%"></div>
<div class="key rhnd" style="top:37.5%;left:96%"></div>
<div class="key lhnd" style="top:51%;left:4%"></div>
<div class="key lhnd" style="top:51%;left:10.5%"></div>
<div class="key lhnd" style="top:49%;left:15.6%"></div>
<div class="key lhnd" style="top:48%;left:20.7%"></div>
<div class="key lhnd" style="top:49%;left:25.7%"></div>
<div class="key lhnd" style="top:50%;left:30.8%"></div>
<div class="key lhnd" style="top:47%;left:36%"></div>
<div class="key rhnd" style="top:47%;left:63.9%"></div>
<div class="key rhnd" style="top:50%;left:69.3%"></div>
<div class="key rhnd" style="top:49%;left:74%"></div>
<div class="key rhnd" style="top:48%;left:79.3%"></div>
<div class="key rhnd" style="top:49%;left:84.4%"></div>
<div class="key rhnd" style="top:51%;left:89.6%"></div>
<div class="key rhnd" style="top:51%;left:96%"></div>
<div class="key lhnd" style="top:65%;left:5%"></div>
<div class="key lhnd" style="top:65%;left:10.5%"></div>
<div class="key lhnd" style="top:63%;left:15.6%"></div>
<div class="key lhnd" style="top:62%;left:20.7%"></div>
<div class="key lhnd" style="top:63%;left:25.7%"></div>
<div class="key rhnd" style="top:63%;left:74%"></div>
<div class="key rhnd" style="top:62%;left:79.3%"></div>
<div class="key rhnd" style="top:63%;left:84.4%"></div>
<div class="key rhnd" style="top:65%;left:89.6%"></div>
<div class="key rhnd" style="top:65%;left:95%"></div>
<div class="key lthb" style="top:62%;left:41%"></div>
<div class="key lthb" style="top:68.6%;left:45.2%"></div>
<div class="key rthb" style="top:65%;left:54.8%"></div>
<div class="key rthb" style="top:58.2%;left:59%"></div>
<div class="key lthb" style="top:80.2%;left:43.3%"></div>
<div class="key rthb" style="top:77%;left:56.7%"></div>
<div class="key lthb" style="top:73%;left:33.5%"></div>
<div class="key lthb" style="top:79%;left:38%"></div>
<div class="key lthb" style="top:92.6%;left:41.5%"></div>
<div class="key rthb" style="top:89.4%;left:58.6%"></div>
<div class="key rthb" style="top:77%;left:62%"></div>
<div class="key rthb" style="top:71%;left:66.8%"></div>
</div>

### num_fn tap
<div class=layout>
<div class="key lhnd" style="top:10.5%;left:4%">😊</div>
<div class="key lhnd" style="top:9.9%;left:10.5%">F1</div>
<div class="key lhnd" style="top:7.5%;left:15.6%">F2</div>
<div class="key lhnd" style="top:6.5%;left:20.7%">F3</div>
<div class="key lhnd" style="top:7.8%;left:25.7%">F4</div>
<div class="key lhnd" style="top:8.5%;left:30.8%">F5</div>
<div class="key lhnd" style="top:8.5%;left:36%">✅</div>
<div class="key rhnd" style="top:8.5%;left:63.9%">©</div>
<div class="key rhnd" style="top:8.5%;left:69.3%">F6</div>
<div class="key rhnd" style="top:7.8%;left:74%">F7</div>
<div class="key rhnd" style="top:6.5%;left:79.3%">F8</div>
<div class="key rhnd" style="top:7.5%;left:84.4%">F9</div>
<div class="key rhnd" style="top:9.9%;left:89.6%;font-size:70.0%">F10</div>
<div class="key rhnd" style="top:10.5%;left:96%;font-size:70.0%">F11</div>
<div class="key lhnd" style="top:24.4%;left:4%">🤣</div>
<div class="key lhnd" style="top:23.8%;left:10.5%">🐞</div>
<div class="key lhnd" style="top:21.4%;left:15.6%">↕</div>
<div class="key lhnd" style="top:20.4%;left:20.7%">↖</div>
<div class="key lhnd" style="top:20.8%;left:25.7%">↑</div>
<div class="key lhnd" style="top:21.5%;left:30.8%">↗</div>
<div class="key lhnd" style="top:25.5%;left:36%">❌</div>
<div class="key rhnd" style="top:25.5%;left:63.9%">/</div>
<div class="key rhnd" style="top:22.7%;left:69.3%">7</div>
<div class="key rhnd" style="top:20.8%;left:74%">8</div>
<div class="key rhnd" style="top:20.4%;left:79.3%">9</div>
<div class="key rhnd" style="top:21.4%;left:84.4%">-</div>
<div class="key rhnd" style="top:23.8%;left:89.6%">∞</div>
<div class="key rhnd" style="top:24.4%;left:96%;font-size:70.0%">F12</div>
<div class="key lhnd" style="top:37.5%;left:4%">🤯</div>
<div class="key lhnd" style="top:38.8%;left:10.5%">👀</div>
<div class="key lhnd" style="top:36.4%;left:15.6%">↔</div>
<div class="key lhnd" style="top:35.4%;left:20.7%">←</div>
<div class="key lhnd" style="top:35.8%;left:25.7%">❤️</div>
<div class="key lhnd" style="top:36.5%;left:30.8%">→</div>
<div class="key rhnd" style="top:37.7%;left:69.3%">4</div>
<div class="key rhnd" style="top:35.8%;left:74%">5</div>
<div class="key rhnd" style="top:35.4%;left:79.3%">6</div>
<div class="key rhnd" style="top:36.4%;left:84.4%">+</div>
<div class="key rhnd" style="top:38.8%;left:89.6%;font-size:30.0%">XXXXXXX</div>
<div class="key rhnd" style="top:37.5%;left:96%">🌴</div>
<div class="key lhnd" style="top:51%;left:4%">🫡</div>
<div class="key lhnd" style="top:51%;left:10.5%">🎶</div>
<div class="key lhnd" style="top:49%;left:15.6%">⤢</div>
<div class="key lhnd" style="top:48%;left:20.7%">↙</div>
<div class="key lhnd" style="top:49%;left:25.7%">↓</div>
<div class="key lhnd" style="top:50%;left:30.8%">↘</div>
<div class="key lhnd" style="top:47%;left:36%">⚠️</div>
<div class="key rhnd" style="top:47%;left:63.9%">*</div>
<div class="key rhnd" style="top:50%;left:69.3%">1</div>
<div class="key rhnd" style="top:49%;left:74%">2</div>
<div class="key rhnd" style="top:48%;left:79.3%">3</div>
<div class="key rhnd" style="top:49%;left:84.4%">=</div>
<div class="key rhnd" style="top:51%;left:89.6%;font-size:30.0%">XXXXXXX</div>
<div class="key rhnd" style="top:51%;left:96%;font-size:30.0%">NUM_LOCK</div>
<div class="key lhnd" style="top:65%;left:5%">🫠</div>
<div class="key lhnd" style="top:65%;left:10.5%;font-size:30.0%"><img src=icon/keypad.png></div>
<div class="key lhnd" style="top:63%;left:15.6%;font-size:30.0%">LEFT_CTRL</div>
<div class="key lhnd" style="top:62%;left:20.7%;font-size:30.0%">LEFT_GUI</div>
<div class="key lhnd" style="top:63%;left:25.7%;font-size:30.0%">LEFT_ALT</div>
<div class="key rhnd" style="top:63%;left:74%">0</div>
<div class="key rhnd" style="top:62%;left:79.3%">.</div>
<div class="key rhnd" style="top:63%;left:84.4%;font-size:30.0%"><img src=icon/enter.png></div>
<div class="key rhnd" style="top:65%;left:89.6%;font-size:30.0%">XXXXXXX</div>
<div class="key rhnd" style="top:65%;left:95%">🔗</div>
<div class="key lthb" style="top:62%;left:41%;font-size:30.0%"><img src=icon/home.png></div>
<div class="key lthb" style="top:68.6%;left:45.2%;font-size:30.0%"><img src=icon/end.png></div>
<div class="key rthb" style="top:65%;left:54.8%;font-size:30.0%"><img src=icon/escape.png></div>
<div class="key rthb" style="top:58.2%;left:59%;font-size:30.0%"><img src=icon/delete.png></div>
<div class="key lthb" style="top:80.2%;left:43.3%">⇨</div>
<div class="key rthb" style="top:77%;left:56.7%">⇧</div>
<div class="key lthb" style="top:73%;left:33.5%;font-size:30.0%"><img src=icon/enter.png></div>
<div class="key lthb" style="top:79%;left:38%;font-size:30.0%"><img src=icon/tab.png></div>
<div class="key lthb" style="top:92.6%;left:41.5%">⇦</div>
<div class="key rthb" style="top:89.4%;left:58.6%">⇩</div>
<div class="key rthb" style="top:77%;left:62%;font-size:30.0%"><img src=icon/backspace.png></div>
<div class="key rthb" style="top:71%;left:66.8%;font-size:30.0%"><img src=icon/space.png></div>
</div>

### num_fn hold
<div class=layout>
<div class="key lhnd" style="top:10.5%;left:4%"></div>
<div class="key lhnd" style="top:9.9%;left:10.5%"></div>
<div class="key lhnd" style="top:7.5%;left:15.6%"></div>
<div class="key lhnd" style="top:6.5%;left:20.7%"></div>
<div class="key lhnd" style="top:7.8%;left:25.7%"></div>
<div class="key lhnd" style="top:8.5%;left:30.8%"></div>
<div class="key lhnd" style="top:8.5%;left:36%"></div>
<div class="key rhnd" style="top:8.5%;left:63.9%">®</div>
<div class="key rhnd" style="top:8.5%;left:69.3%"></div>
<div class="key rhnd" style="top:7.8%;left:74%"></div>
<div class="key rhnd" style="top:6.5%;left:79.3%"></div>
<div class="key rhnd" style="top:7.5%;left:84.4%"></div>
<div class="key rhnd" style="top:9.9%;left:89.6%"></div>
<div class="key rhnd" style="top:10.5%;left:96%"></div>
<div class="key lhnd" style="top:24.4%;left:4%"></div>
<div class="key lhnd" style="top:23.8%;left:10.5%"></div>
<div class="key lhnd" style="top:21.4%;left:15.6%">⬍</div>
<div class="key lhnd" style="top:20.4%;left:20.7%">⬉</div>
<div class="key lhnd" style="top:20.8%;left:25.7%">⬆</div>
<div class="key lhnd" style="top:21.5%;left:30.8%">⬈</div>
<div class="key lhnd" style="top:25.5%;left:36%"></div>
<div class="key rhnd" style="top:25.5%;left:63.9%">÷</div>
<div class="key rhnd" style="top:22.7%;left:69.3%"></div>
<div class="key rhnd" style="top:20.8%;left:74%"></div>
<div class="key rhnd" style="top:20.4%;left:79.3%"></div>
<div class="key rhnd" style="top:21.4%;left:84.4%">−</div>
<div class="key rhnd" style="top:23.8%;left:89.6%">⧜</div>
<div class="key rhnd" style="top:24.4%;left:96%"></div>
<div class="key lhnd" style="top:37.5%;left:4%"></div>
<div class="key lhnd" style="top:38.8%;left:10.5%"></div>
<div class="key lhnd" style="top:36.4%;left:15.6%">⬌</div>
<div class="key lhnd" style="top:35.4%;left:20.7%">⬅</div>
<div class="key lhnd" style="top:35.8%;left:25.7%"></div>
<div class="key lhnd" style="top:36.5%;left:30.8%">➡</div>
<div class="key rhnd" style="top:37.7%;left:69.3%"></div>
<div class="key rhnd" style="top:35.8%;left:74%"></div>
<div class="key rhnd" style="top:35.4%;left:79.3%"></div>
<div class="key rhnd" style="top:36.4%;left:84.4%">±</div>
<div class="key rhnd" style="top:38.8%;left:89.6%"></div>
<div class="key rhnd" style="top:37.5%;left:96%"></div>
<div class="key lhnd" style="top:51%;left:4%"></div>
<div class="key lhnd" style="top:51%;left:10.5%"></div>
<div class="key lhnd" style="top:49%;left:15.6%">⤡</div>
<div class="key lhnd" style="top:48%;left:20.7%">⬋</div>
<div class="key lhnd" style="top:49%;left:25.7%">⬇</div>
<div class="key lhnd" style="top:50%;left:30.8%">⬊</div>
<div class="key lhnd" style="top:47%;left:36%"></div>
<div class="key rhnd" style="top:47%;left:63.9%">×</div>
<div class="key rhnd" style="top:50%;left:69.3%"></div>
<div class="key rhnd" style="top:49%;left:74%"></div>
<div class="key rhnd" style="top:48%;left:79.3%"></div>
<div class="key rhnd" style="top:49%;left:84.4%">≠</div>
<div class="key rhnd" style="top:51%;left:89.6%"></div>
<div class="key rhnd" style="top:51%;left:96%"></div>
<div class="key lhnd" style="top:65%;left:5%"></div>
<div class="key lhnd" style="top:65%;left:10.5%;font-size:30.0%"><img src=icon/keypad.png></div>
<div class="key lhnd" style="top:63%;left:15.6%"></div>
<div class="key lhnd" style="top:62%;left:20.7%"></div>
<div class="key lhnd" style="top:63%;left:25.7%"></div>
<div class="key rhnd" style="top:63%;left:74%"></div>
<div class="key rhnd" style="top:62%;left:79.3%"></div>
<div class="key rhnd" style="top:63%;left:84.4%"></div>
<div class="key rhnd" style="top:65%;left:89.6%"></div>
<div class="key rhnd" style="top:65%;left:95%"></div>
<div class="key lthb" style="top:62%;left:41%"></div>
<div class="key lthb" style="top:68.6%;left:45.2%"></div>
<div class="key rthb" style="top:65%;left:54.8%"></div>
<div class="key rthb" style="top:58.2%;left:59%"></div>
<div class="key lthb" style="top:80.2%;left:43.3%"></div>
<div class="key rthb" style="top:77%;left:56.7%"></div>
<div class="key lthb" style="top:73%;left:33.5%"></div>
<div class="key lthb" style="top:79%;left:38%"></div>
<div class="key lthb" style="top:92.6%;left:41.5%"></div>
<div class="key rthb" style="top:89.4%;left:58.6%"></div>
<div class="key rthb" style="top:77%;left:62%"></div>
<div class="key rthb" style="top:71%;left:66.8%"></div>
</div>

### num_fn shift
<div class=layout>
<div class="key lhnd" style="top:10.5%;left:4%"></div>
<div class="key lhnd" style="top:9.9%;left:10.5%"></div>
<div class="key lhnd" style="top:7.5%;left:15.6%"></div>
<div class="key lhnd" style="top:6.5%;left:20.7%"></div>
<div class="key lhnd" style="top:7.8%;left:25.7%"></div>
<div class="key lhnd" style="top:8.5%;left:30.8%"></div>
<div class="key lhnd" style="top:8.5%;left:36%"></div>
<div class="key rhnd" style="top:8.5%;left:63.9%"></div>
<div class="key rhnd" style="top:8.5%;left:69.3%"></div>
<div class="key rhnd" style="top:7.8%;left:74%"></div>
<div class="key rhnd" style="top:6.5%;left:79.3%"></div>
<div class="key rhnd" style="top:7.5%;left:84.4%"></div>
<div class="key rhnd" style="top:9.9%;left:89.6%"></div>
<div class="key rhnd" style="top:10.5%;left:96%"></div>
<div class="key lhnd" style="top:24.4%;left:4%"></div>
<div class="key lhnd" style="top:23.8%;left:10.5%"></div>
<div class="key lhnd" style="top:21.4%;left:15.6%"></div>
<div class="key lhnd" style="top:20.4%;left:20.7%"></div>
<div class="key lhnd" style="top:20.8%;left:25.7%"></div>
<div class="key lhnd" style="top:21.5%;left:30.8%"></div>
<div class="key lhnd" style="top:25.5%;left:36%"></div>
<div class="key rhnd" style="top:25.5%;left:63.9%"></div>
<div class="key rhnd" style="top:22.7%;left:69.3%"></div>
<div class="key rhnd" style="top:20.8%;left:74%"></div>
<div class="key rhnd" style="top:20.4%;left:79.3%"></div>
<div class="key rhnd" style="top:21.4%;left:84.4%"></div>
<div class="key rhnd" style="top:23.8%;left:89.6%"></div>
<div class="key rhnd" style="top:24.4%;left:96%"></div>
<div class="key lhnd" style="top:37.5%;left:4%"></div>
<div class="key lhnd" style="top:38.8%;left:10.5%"></div>
<div class="key lhnd" style="top:36.4%;left:15.6%"></div>
<div class="key lhnd" style="top:35.4%;left:20.7%"></div>
<div class="key lhnd" style="top:35.8%;left:25.7%"></div>
<div class="key lhnd" style="top:36.5%;left:30.8%"></div>
<div class="key rhnd" style="top:37.7%;left:69.3%"></div>
<div class="key rhnd" style="top:35.8%;left:74%"></div>
<div class="key rhnd" style="top:35.4%;left:79.3%"></div>
<div class="key rhnd" style="top:36.4%;left:84.4%"></div>
<div class="key rhnd" style="top:38.8%;left:89.6%"></div>
<div class="key rhnd" style="top:37.5%;left:96%"></div>
<div class="key lhnd" style="top:51%;left:4%"></div>
<div class="key lhnd" style="top:51%;left:10.5%"></div>
<div class="key lhnd" style="top:49%;left:15.6%"></div>
<div class="key lhnd" style="top:48%;left:20.7%"></div>
<div class="key lhnd" style="top:49%;left:25.7%"></div>
<div class="key lhnd" style="top:50%;left:30.8%"></div>
<div class="key lhnd" style="top:47%;left:36%"></div>
<div class="key rhnd" style="top:47%;left:63.9%"></div>
<div class="key rhnd" style="top:50%;left:69.3%"></div>
<div class="key rhnd" style="top:49%;left:74%"></div>
<div class="key rhnd" style="top:48%;left:79.3%"></div>
<div class="key rhnd" style="top:49%;left:84.4%"></div>
<div class="key rhnd" style="top:51%;left:89.6%"></div>
<div class="key rhnd" style="top:51%;left:96%"></div>
<div class="key lhnd" style="top:65%;left:5%"></div>
<div class="key lhnd" style="top:65%;left:10.5%">👎</div>
<div class="key lhnd" style="top:63%;left:15.6%"></div>
<div class="key lhnd" style="top:62%;left:20.7%"></div>
<div class="key lhnd" style="top:63%;left:25.7%"></div>
<div class="key rhnd" style="top:63%;left:74%"></div>
<div class="key rhnd" style="top:62%;left:79.3%"></div>
<div class="key rhnd" style="top:63%;left:84.4%"></div>
<div class="key rhnd" style="top:65%;left:89.6%"></div>
<div class="key rhnd" style="top:65%;left:95%"></div>
<div class="key lthb" style="top:62%;left:41%"></div>
<div class="key lthb" style="top:68.6%;left:45.2%"></div>
<div class="key rthb" style="top:65%;left:54.8%"></div>
<div class="key rthb" style="top:58.2%;left:59%"></div>
<div class="key lthb" style="top:80.2%;left:43.3%"></div>
<div class="key rthb" style="top:77%;left:56.7%"></div>
<div class="key lthb" style="top:73%;left:33.5%"></div>
<div class="key lthb" style="top:79%;left:38%"></div>
<div class="key lthb" style="top:92.6%;left:41.5%"></div>
<div class="key rthb" style="top:89.4%;left:58.6%"></div>
<div class="key rthb" style="top:77%;left:62%"></div>
<div class="key rthb" style="top:71%;left:66.8%"></div>
</div>

### num_fn dtap
<div class=layout>
<div class="key lhnd" style="top:10.5%;left:4%"></div>
<div class="key lhnd" style="top:9.9%;left:10.5%"></div>
<div class="key lhnd" style="top:7.5%;left:15.6%"></div>
<div class="key lhnd" style="top:6.5%;left:20.7%"></div>
<div class="key lhnd" style="top:7.8%;left:25.7%"></div>
<div class="key lhnd" style="top:8.5%;left:30.8%"></div>
<div class="key lhnd" style="top:8.5%;left:36%"></div>
<div class="key rhnd" style="top:8.5%;left:63.9%">™</div>
<div class="key rhnd" style="top:8.5%;left:69.3%"></div>
<div class="key rhnd" style="top:7.8%;left:74%"></div>
<div class="key rhnd" style="top:6.5%;left:79.3%"></div>
<div class="key rhnd" style="top:7.5%;left:84.4%"></div>
<div class="key rhnd" style="top:9.9%;left:89.6%"></div>
<div class="key rhnd" style="top:10.5%;left:96%"></div>
<div class="key lhnd" style="top:24.4%;left:4%"></div>
<div class="key lhnd" style="top:23.8%;left:10.5%"></div>
<div class="key lhnd" style="top:21.4%;left:15.6%">⇳</div>
<div class="key lhnd" style="top:20.4%;left:20.7%">⬁</div>
<div class="key lhnd" style="top:20.8%;left:25.7%">⇧</div>
<div class="key lhnd" style="top:21.5%;left:30.8%">⬀</div>
<div class="key lhnd" style="top:25.5%;left:36%"></div>
<div class="key rhnd" style="top:25.5%;left:63.9%">➗</div>
<div class="key rhnd" style="top:22.7%;left:69.3%"></div>
<div class="key rhnd" style="top:20.8%;left:74%"></div>
<div class="key rhnd" style="top:20.4%;left:79.3%"></div>
<div class="key rhnd" style="top:21.4%;left:84.4%">➖</div>
<div class="key rhnd" style="top:23.8%;left:89.6%">⧝</div>
<div class="key rhnd" style="top:24.4%;left:96%"></div>
<div class="key lhnd" style="top:37.5%;left:4%"></div>
<div class="key lhnd" style="top:38.8%;left:10.5%"></div>
<div class="key lhnd" style="top:36.4%;left:15.6%">⬄</div>
<div class="key lhnd" style="top:35.4%;left:20.7%">⇦</div>
<div class="key lhnd" style="top:35.8%;left:25.7%"></div>
<div class="key lhnd" style="top:36.5%;left:30.8%">⇨</div>
<div class="key rhnd" style="top:37.7%;left:69.3%"></div>
<div class="key rhnd" style="top:35.8%;left:74%"></div>
<div class="key rhnd" style="top:35.4%;left:79.3%"></div>
<div class="key rhnd" style="top:36.4%;left:84.4%">➕</div>
<div class="key rhnd" style="top:38.8%;left:89.6%"></div>
<div class="key rhnd" style="top:37.5%;left:96%"></div>
<div class="key lhnd" style="top:51%;left:4%"></div>
<div class="key lhnd" style="top:51%;left:10.5%"></div>
<div class="key lhnd" style="top:49%;left:15.6%"></div>
<div class="key lhnd" style="top:48%;left:20.7%">⬃</div>
<div class="key lhnd" style="top:49%;left:25.7%">⇩</div>
<div class="key lhnd" style="top:50%;left:30.8%">⬂</div>
<div class="key lhnd" style="top:47%;left:36%"></div>
<div class="key rhnd" style="top:47%;left:63.9%">✖</div>
<div class="key rhnd" style="top:50%;left:69.3%"></div>
<div class="key rhnd" style="top:49%;left:74%"></div>
<div class="key rhnd" style="top:48%;left:79.3%"></div>
<div class="key rhnd" style="top:49%;left:84.4%">🟰</div>
<div class="key rhnd" style="top:51%;left:89.6%"></div>
<div class="key rhnd" style="top:51%;left:96%"></div>
<div class="key lhnd" style="top:65%;left:5%"></div>
<div class="key lhnd" style="top:65%;left:10.5%;font-size:30.0%">qwerty</div>
<div class="key lhnd" style="top:63%;left:15.6%"></div>
<div class="key lhnd" style="top:62%;left:20.7%"></div>
<div class="key lhnd" style="top:63%;left:25.7%"></div>
<div class="key rhnd" style="top:63%;left:74%"></div>
<div class="key rhnd" style="top:62%;left:79.3%"></div>
<div class="key rhnd" style="top:63%;left:84.4%"></div>
<div class="key rhnd" style="top:65%;left:89.6%"></div>
<div class="key rhnd" style="top:65%;left:95%"></div>
<div class="key lthb" style="top:62%;left:41%;font-size:30.0%"><img src=icon/top.png></div>
<div class="key lthb" style="top:68.6%;left:45.2%;font-size:30.0%"><img src=icon/bottom.png></div>
<div class="key rthb" style="top:65%;left:54.8%"></div>
<div class="key rthb" style="top:58.2%;left:59%"></div>
<div class="key lthb" style="top:80.2%;left:43.3%"></div>
<div class="key rthb" style="top:77%;left:56.7%"></div>
<div class="key lthb" style="top:73%;left:33.5%"></div>
<div class="key lthb" style="top:79%;left:38%"></div>
<div class="key lthb" style="top:92.6%;left:41.5%"></div>
<div class="key rthb" style="top:89.4%;left:58.6%"></div>
<div class="key rthb" style="top:77%;left:62%"></div>
<div class="key rthb" style="top:71%;left:66.8%"></div>
</div>

### num_fn dhold
<div class=layout>
<div class="key lhnd" style="top:10.5%;left:4%"></div>
<div class="key lhnd" style="top:9.9%;left:10.5%"></div>
<div class="key lhnd" style="top:7.5%;left:15.6%"></div>
<div class="key lhnd" style="top:6.5%;left:20.7%"></div>
<div class="key lhnd" style="top:7.8%;left:25.7%"></div>
<div class="key lhnd" style="top:8.5%;left:30.8%"></div>
<div class="key lhnd" style="top:8.5%;left:36%"></div>
<div class="key rhnd" style="top:8.5%;left:63.9%"></div>
<div class="key rhnd" style="top:8.5%;left:69.3%"></div>
<div class="key rhnd" style="top:7.8%;left:74%"></div>
<div class="key rhnd" style="top:6.5%;left:79.3%"></div>
<div class="key rhnd" style="top:7.5%;left:84.4%"></div>
<div class="key rhnd" style="top:9.9%;left:89.6%"></div>
<div class="key rhnd" style="top:10.5%;left:96%"></div>
<div class="key lhnd" style="top:24.4%;left:4%"></div>
<div class="key lhnd" style="top:23.8%;left:10.5%"></div>
<div class="key lhnd" style="top:21.4%;left:15.6%">⇕</div>
<div class="key lhnd" style="top:20.4%;left:20.7%">⇖</div>
<div class="key lhnd" style="top:20.8%;left:25.7%">⇑</div>
<div class="key lhnd" style="top:21.5%;left:30.8%">⇗</div>
<div class="key lhnd" style="top:25.5%;left:36%"></div>
<div class="key rhnd" style="top:25.5%;left:63.9%"></div>
<div class="key rhnd" style="top:22.7%;left:69.3%"></div>
<div class="key rhnd" style="top:20.8%;left:74%"></div>
<div class="key rhnd" style="top:20.4%;left:79.3%"></div>
<div class="key rhnd" style="top:21.4%;left:84.4%"></div>
<div class="key rhnd" style="top:23.8%;left:89.6%">⧞</div>
<div class="key rhnd" style="top:24.4%;left:96%"></div>
<div class="key lhnd" style="top:37.5%;left:4%"></div>
<div class="key lhnd" style="top:38.8%;left:10.5%"></div>
<div class="key lhnd" style="top:36.4%;left:15.6%">⇔</div>
<div class="key lhnd" style="top:35.4%;left:20.7%">⇐</div>
<div class="key lhnd" style="top:35.8%;left:25.7%"></div>
<div class="key lhnd" style="top:36.5%;left:30.8%">⇒</div>
<div class="key rhnd" style="top:37.7%;left:69.3%"></div>
<div class="key rhnd" style="top:35.8%;left:74%"></div>
<div class="key rhnd" style="top:35.4%;left:79.3%"></div>
<div class="key rhnd" style="top:36.4%;left:84.4%"></div>
<div class="key rhnd" style="top:38.8%;left:89.6%"></div>
<div class="key rhnd" style="top:37.5%;left:96%"></div>
<div class="key lhnd" style="top:51%;left:4%"></div>
<div class="key lhnd" style="top:51%;left:10.5%"></div>
<div class="key lhnd" style="top:49%;left:15.6%"></div>
<div class="key lhnd" style="top:48%;left:20.7%">⇙</div>
<div class="key lhnd" style="top:49%;left:25.7%">⇓</div>
<div class="key lhnd" style="top:50%;left:30.8%">⇘</div>
<div class="key lhnd" style="top:47%;left:36%"></div>
<div class="key rhnd" style="top:47%;left:63.9%"></div>
<div class="key rhnd" style="top:50%;left:69.3%"></div>
<div class="key rhnd" style="top:49%;left:74%"></div>
<div class="key rhnd" style="top:48%;left:79.3%"></div>
<div class="key rhnd" style="top:49%;left:84.4%">≈</div>
<div class="key rhnd" style="top:51%;left:89.6%"></div>
<div class="key rhnd" style="top:51%;left:96%"></div>
<div class="key lhnd" style="top:65%;left:5%"></div>
<div class="key lhnd" style="top:65%;left:10.5%;font-size:30.0%">qwerty</div>
<div class="key lhnd" style="top:63%;left:15.6%"></div>
<div class="key lhnd" style="top:62%;left:20.7%"></div>
<div class="key lhnd" style="top:63%;left:25.7%"></div>
<div class="key rhnd" style="top:63%;left:74%"></div>
<div class="key rhnd" style="top:62%;left:79.3%"></div>
<div class="key rhnd" style="top:63%;left:84.4%"></div>
<div class="key rhnd" style="top:65%;left:89.6%"></div>
<div class="key rhnd" style="top:65%;left:95%"></div>
<div class="key lthb" style="top:62%;left:41%"></div>
<div class="key lthb" style="top:68.6%;left:45.2%"></div>
<div class="key rthb" style="top:65%;left:54.8%"></div>
<div class="key rthb" style="top:58.2%;left:59%"></div>
<div class="key lthb" style="top:80.2%;left:43.3%"></div>
<div class="key rthb" style="top:77%;left:56.7%"></div>
<div class="key lthb" style="top:73%;left:33.5%"></div>
<div class="key lthb" style="top:79%;left:38%"></div>
<div class="key lthb" style="top:92.6%;left:41.5%"></div>
<div class="key rthb" style="top:89.4%;left:58.6%"></div>
<div class="key rthb" style="top:77%;left:62%"></div>
<div class="key rthb" style="top:71%;left:66.8%"></div>
</div>

### num_fn ttap
<div class=layout>
<div class="key lhnd" style="top:10.5%;left:4%"></div>
<div class="key lhnd" style="top:9.9%;left:10.5%"></div>
<div class="key lhnd" style="top:7.5%;left:15.6%"></div>
<div class="key lhnd" style="top:6.5%;left:20.7%"></div>
<div class="key lhnd" style="top:7.8%;left:25.7%"></div>
<div class="key lhnd" style="top:8.5%;left:30.8%"></div>
<div class="key lhnd" style="top:8.5%;left:36%"></div>
<div class="key rhnd" style="top:8.5%;left:63.9%"></div>
<div class="key rhnd" style="top:8.5%;left:69.3%"></div>
<div class="key rhnd" style="top:7.8%;left:74%"></div>
<div class="key rhnd" style="top:6.5%;left:79.3%"></div>
<div class="key rhnd" style="top:7.5%;left:84.4%"></div>
<div class="key rhnd" style="top:9.9%;left:89.6%"></div>
<div class="key rhnd" style="top:10.5%;left:96%"></div>
<div class="key lhnd" style="top:24.4%;left:4%"></div>
<div class="key lhnd" style="top:23.8%;left:10.5%"></div>
<div class="key lhnd" style="top:21.4%;left:15.6%"></div>
<div class="key lhnd" style="top:20.4%;left:20.7%">🡴</div>
<div class="key lhnd" style="top:20.8%;left:25.7%">🡱</div>
<div class="key lhnd" style="top:21.5%;left:30.8%">🡵</div>
<div class="key lhnd" style="top:25.5%;left:36%"></div>
<div class="key rhnd" style="top:25.5%;left:63.9%"></div>
<div class="key rhnd" style="top:22.7%;left:69.3%"></div>
<div class="key rhnd" style="top:20.8%;left:74%"></div>
<div class="key rhnd" style="top:20.4%;left:79.3%"></div>
<div class="key rhnd" style="top:21.4%;left:84.4%"></div>
<div class="key rhnd" style="top:23.8%;left:89.6%"></div>
<div class="key rhnd" style="top:24.4%;left:96%"></div>
<div class="key lhnd" style="top:37.5%;left:4%"></div>
<div class="key lhnd" style="top:38.8%;left:10.5%"></div>
<div class="key lhnd" style="top:36.4%;left:15.6%"></div>
<div class="key lhnd" style="top:35.4%;left:20.7%">🡰</div>
<div class="key lhnd" style="top:35.8%;left:25.7%"></div>
<div class="key lhnd" style="top:36.5%;left:30.8%">🡲</div>
<div class="key rhnd" style="top:37.7%;left:69.3%"></div>
<div class="key rhnd" style="top:35.8%;left:74%"></div>
<div class="key rhnd" style="top:35.4%;left:79.3%"></div>
<div class="key rhnd" style="top:36.4%;left:84.4%"></div>
<div class="key rhnd" style="top:38.8%;left:89.6%"></div>
<div class="key rhnd" style="top:37.5%;left:96%"></div>
<div class="key lhnd" style="top:51%;left:4%"></div>
<div class="key lhnd" style="top:51%;left:10.5%"></div>
<div class="key lhnd" style="top:49%;left:15.6%"></div>
<div class="key lhnd" style="top:48%;left:20.7%">🡷</div>
<div class="key lhnd" style="top:49%;left:25.7%">🡳</div>
<div class="key lhnd" style="top:50%;left:30.8%">🡶</div>
<div class="key lhnd" style="top:47%;left:36%"></div>
<div class="key rhnd" style="top:47%;left:63.9%"></div>
<div class="key rhnd" style="top:50%;left:69.3%"></div>
<div class="key rhnd" style="top:49%;left:74%"></div>
<div class="key rhnd" style="top:48%;left:79.3%"></div>
<div class="key rhnd" style="top:49%;left:84.4%"></div>
<div class="key rhnd" style="top:51%;left:89.6%"></div>
<div class="key rhnd" style="top:51%;left:96%"></div>
<div class="key lhnd" style="top:65%;left:5%"></div>
<div class="key lhnd" style="top:65%;left:10.5%"></div>
<div class="key lhnd" style="top:63%;left:15.6%"></div>
<div class="key lhnd" style="top:62%;left:20.7%"></div>
<div class="key lhnd" style="top:63%;left:25.7%"></div>
<div class="key rhnd" style="top:63%;left:74%"></div>
<div class="key rhnd" style="top:62%;left:79.3%"></div>
<div class="key rhnd" style="top:63%;left:84.4%"></div>
<div class="key rhnd" style="top:65%;left:89.6%"></div>
<div class="key rhnd" style="top:65%;left:95%"></div>
<div class="key lthb" style="top:62%;left:41%"></div>
<div class="key lthb" style="top:68.6%;left:45.2%"></div>
<div class="key rthb" style="top:65%;left:54.8%"></div>
<div class="key rthb" style="top:58.2%;left:59%"></div>
<div class="key lthb" style="top:80.2%;left:43.3%"></div>
<div class="key rthb" style="top:77%;left:56.7%"></div>
<div class="key lthb" style="top:73%;left:33.5%"></div>
<div class="key lthb" style="top:79%;left:38%"></div>
<div class="key lthb" style="top:92.6%;left:41.5%"></div>
<div class="key rthb" style="top:89.4%;left:58.6%"></div>
<div class="key rthb" style="top:77%;left:62%"></div>
<div class="key rthb" style="top:71%;left:66.8%"></div>
</div>

### num_fn thold
<div class=layout>
<div class="key lhnd" style="top:10.5%;left:4%"></div>
<div class="key lhnd" style="top:9.9%;left:10.5%"></div>
<div class="key lhnd" style="top:7.5%;left:15.6%"></div>
<div class="key lhnd" style="top:6.5%;left:20.7%"></div>
<div class="key lhnd" style="top:7.8%;left:25.7%"></div>
<div class="key lhnd" style="top:8.5%;left:30.8%"></div>
<div class="key lhnd" style="top:8.5%;left:36%"></div>
<div class="key rhnd" style="top:8.5%;left:63.9%"></div>
<div class="key rhnd" style="top:8.5%;left:69.3%"></div>
<div class="key rhnd" style="top:7.8%;left:74%"></div>
<div class="key rhnd" style="top:6.5%;left:79.3%"></div>
<div class="key rhnd" style="top:7.5%;left:84.4%"></div>
<div class="key rhnd" style="top:9.9%;left:89.6%"></div>
<div class="key rhnd" style="top:10.5%;left:96%"></div>
<div class="key lhnd" style="top:24.4%;left:4%"></div>
<div class="key lhnd" style="top:23.8%;left:10.5%"></div>
<div class="key lhnd" style="top:21.4%;left:15.6%"></div>
<div class="key lhnd" style="top:20.4%;left:20.7%">🢄</div>
<div class="key lhnd" style="top:20.8%;left:25.7%">🢁</div>
<div class="key lhnd" style="top:21.5%;left:30.8%">🢅</div>
<div class="key lhnd" style="top:25.5%;left:36%"></div>
<div class="key rhnd" style="top:25.5%;left:63.9%"></div>
<div class="key rhnd" style="top:22.7%;left:69.3%"></div>
<div class="key rhnd" style="top:20.8%;left:74%"></div>
<div class="key rhnd" style="top:20.4%;left:79.3%"></div>
<div class="key rhnd" style="top:21.4%;left:84.4%"></div>
<div class="key rhnd" style="top:23.8%;left:89.6%"></div>
<div class="key rhnd" style="top:24.4%;left:96%"></div>
<div class="key lhnd" style="top:37.5%;left:4%"></div>
<div class="key lhnd" style="top:38.8%;left:10.5%"></div>
<div class="key lhnd" style="top:36.4%;left:15.6%"></div>
<div class="key lhnd" style="top:35.4%;left:20.7%">🢀</div>
<div class="key lhnd" style="top:35.8%;left:25.7%"></div>
<div class="key lhnd" style="top:36.5%;left:30.8%">🢂</div>
<div class="key rhnd" style="top:37.7%;left:69.3%"></div>
<div class="key rhnd" style="top:35.8%;left:74%"></div>
<div class="key rhnd" style="top:35.4%;left:79.3%"></div>
<div class="key rhnd" style="top:36.4%;left:84.4%"></div>
<div class="key rhnd" style="top:38.8%;left:89.6%"></div>
<div class="key rhnd" style="top:37.5%;left:96%"></div>
<div class="key lhnd" style="top:51%;left:4%"></div>
<div class="key lhnd" style="top:51%;left:10.5%"></div>
<div class="key lhnd" style="top:49%;left:15.6%"></div>
<div class="key lhnd" style="top:48%;left:20.7%">🢇</div>
<div class="key lhnd" style="top:49%;left:25.7%">🢃</div>
<div class="key lhnd" style="top:50%;left:30.8%">🢆</div>
<div class="key lhnd" style="top:47%;left:36%"></div>
<div class="key rhnd" style="top:47%;left:63.9%"></div>
<div class="key rhnd" style="top:50%;left:69.3%"></div>
<div class="key rhnd" style="top:49%;left:74%"></div>
<div class="key rhnd" style="top:48%;left:79.3%"></div>
<div class="key rhnd" style="top:49%;left:84.4%"></div>
<div class="key rhnd" style="top:51%;left:89.6%"></div>
<div class="key rhnd" style="top:51%;left:96%"></div>
<div class="key lhnd" style="top:65%;left:5%"></div>
<div class="key lhnd" style="top:65%;left:10.5%"></div>
<div class="key lhnd" style="top:63%;left:15.6%"></div>
<div class="key lhnd" style="top:62%;left:20.7%"></div>
<div class="key lhnd" style="top:63%;left:25.7%"></div>
<div class="key rhnd" style="top:63%;left:74%"></div>
<div class="key rhnd" style="top:62%;left:79.3%"></div>
<div class="key rhnd" style="top:63%;left:84.4%"></div>
<div class="key rhnd" style="top:65%;left:89.6%"></div>
<div class="key rhnd" style="top:65%;left:95%"></div>
<div class="key lthb" style="top:62%;left:41%"></div>
<div class="key lthb" style="top:68.6%;left:45.2%"></div>
<div class="key rthb" style="top:65%;left:54.8%"></div>
<div class="key rthb" style="top:58.2%;left:59%"></div>
<div class="key lthb" style="top:80.2%;left:43.3%"></div>
<div class="key rthb" style="top:77%;left:56.7%"></div>
<div class="key lthb" style="top:73%;left:33.5%"></div>
<div class="key lthb" style="top:79%;left:38%"></div>
<div class="key lthb" style="top:92.6%;left:41.5%"></div>
<div class="key rthb" style="top:89.4%;left:58.6%"></div>
<div class="key rthb" style="top:77%;left:62%"></div>
<div class="key rthb" style="top:71%;left:66.8%"></div>
</div>

### qwerty tap
<div class=layout>
<div class="key lhnd" style="top:10.5%;left:4%;font-size:30.0%"><img src=icon/mute-mic.png></div>
<div class="key lhnd" style="top:9.9%;left:10.5%">1</div>
<div class="key lhnd" style="top:7.5%;left:15.6%">2</div>
<div class="key lhnd" style="top:6.5%;left:20.7%">3</div>
<div class="key lhnd" style="top:7.8%;left:25.7%">4</div>
<div class="key lhnd" style="top:8.5%;left:30.8%">5</div>
<div class="key lhnd" style="top:8.5%;left:36%;font-size:30.0%"><img src=icon/play-pause.png></div>
<div class="key rhnd" style="top:8.5%;left:63.9%;font-size:30.0%"><img src=icon/calculator.png></div>
<div class="key rhnd" style="top:8.5%;left:69.3%">6</div>
<div class="key rhnd" style="top:7.8%;left:74%">7</div>
<div class="key rhnd" style="top:6.5%;left:79.3%">8</div>
<div class="key rhnd" style="top:7.5%;left:84.4%">9</div>
<div class="key rhnd" style="top:9.9%;left:89.6%">0</div>
<div class="key rhnd" style="top:10.5%;left:96%;font-size:30.0%"><img src=icon/next-track.png></div>
<div class="key lhnd" style="top:24.4%;left:4%;font-size:30.0%"><img src=icon/volume-up.png></div>
<div class="key lhnd" style="top:23.8%;left:10.5%">q</div>
<div class="key lhnd" style="top:21.4%;left:15.6%">w</div>
<div class="key lhnd" style="top:20.4%;left:20.7%">e</div>
<div class="key lhnd" style="top:20.8%;left:25.7%">r</div>
<div class="key lhnd" style="top:21.5%;left:30.8%">t</div>
<div class="key lhnd" style="top:25.5%;left:36%">=</div>
<div class="key rhnd" style="top:25.5%;left:63.9%">\</div>
<div class="key rhnd" style="top:22.7%;left:69.3%">y</div>
<div class="key rhnd" style="top:20.8%;left:74%">u</div>
<div class="key rhnd" style="top:20.4%;left:79.3%">i</div>
<div class="key rhnd" style="top:21.4%;left:84.4%">o</div>
<div class="key rhnd" style="top:23.8%;left:89.6%">p</div>
<div class="key rhnd" style="top:24.4%;left:96%;font-size:30.0%"><img src=icon/previous-track.png></div>
<div class="key lhnd" style="top:37.5%;left:4%;font-size:30.0%"><img src=icon/volume-down.png></div>
<div class="key lhnd" style="top:38.8%;left:10.5%">a</div>
<div class="key lhnd" style="top:36.4%;left:15.6%">s</div>
<div class="key lhnd" style="top:35.4%;left:20.7%">d</div>
<div class="key lhnd" style="top:35.8%;left:25.7%">f</div>
<div class="key lhnd" style="top:36.5%;left:30.8%">g</div>
<div class="key rhnd" style="top:37.7%;left:69.3%">h</div>
<div class="key rhnd" style="top:35.8%;left:74%">j</div>
<div class="key rhnd" style="top:35.4%;left:79.3%">k</div>
<div class="key rhnd" style="top:36.4%;left:84.4%">l</div>
<div class="key rhnd" style="top:38.8%;left:89.6%">;</div>
<div class="key rhnd" style="top:37.5%;left:96%">"</div>
<div class="key lhnd" style="top:51%;left:4%">(</div>
<div class="key lhnd" style="top:51%;left:10.5%">z</div>
<div class="key lhnd" style="top:49%;left:15.6%">x</div>
<div class="key lhnd" style="top:48%;left:20.7%">c</div>
<div class="key lhnd" style="top:49%;left:25.7%">v</div>
<div class="key lhnd" style="top:50%;left:30.8%">b</div>
<div class="key lhnd" style="top:47%;left:36%">-</div>
<div class="key rhnd" style="top:47%;left:63.9%">`</div>
<div class="key rhnd" style="top:50%;left:69.3%">n</div>
<div class="key rhnd" style="top:49%;left:74%">m</div>
<div class="key rhnd" style="top:48%;left:79.3%">,</div>
<div class="key rhnd" style="top:49%;left:84.4%">.</div>
<div class="key rhnd" style="top:51%;left:89.6%">/</div>
<div class="key rhnd" style="top:51%;left:96%">)</div>
<div class="key lhnd" style="top:65%;left:5%;font-size:30.0%"><img src=icon/screenshot.png></div>
<div class="key lhnd" style="top:65%;left:10.5%;font-size:30.0%"><img src=icon/keypad.png></div>
<div class="key lhnd" style="top:63%;left:15.6%"><</div>
<div class="key lhnd" style="top:62%;left:20.7%">[</div>
<div class="key lhnd" style="top:63%;left:25.7%">{</div>
<div class="key rhnd" style="top:63%;left:74%">}</div>
<div class="key rhnd" style="top:62%;left:79.3%">]</div>
<div class="key rhnd" style="top:63%;left:84.4%">></div>
<div class="key rhnd" style="top:65%;left:89.6%;font-size:30.0%"><img src=icon/page-up.png></div>
<div class="key rhnd" style="top:65%;left:95%;font-size:30.0%"><img src=icon/page-down.png></div>
<div class="key lthb" style="top:62%;left:41%;font-size:30.0%"><img src=icon/home.png></div>
<div class="key lthb" style="top:68.6%;left:45.2%;font-size:30.0%"><img src=icon/end.png></div>
<div class="key rthb" style="top:65%;left:54.8%;font-size:30.0%"><img src=icon/escape.png></div>
<div class="key rthb" style="top:58.2%;left:59%;font-size:30.0%"><img src=icon/delete.png></div>
<div class="key lthb" style="top:80.2%;left:43.3%">⇨</div>
<div class="key rthb" style="top:77%;left:56.7%">⇧</div>
<div class="key lthb" style="top:73%;left:33.5%;font-size:30.0%"><img src=icon/enter.png></div>
<div class="key lthb" style="top:79%;left:38%;font-size:30.0%"><img src=icon/tab.png></div>
<div class="key lthb" style="top:92.6%;left:41.5%">⇦</div>
<div class="key rthb" style="top:89.4%;left:58.6%">⇩</div>
<div class="key rthb" style="top:77%;left:62%;font-size:30.0%"><img src=icon/backspace.png></div>
<div class="key rthb" style="top:71%;left:66.8%;font-size:30.0%"><img src=icon/space.png></div>
</div>

## Icon credits

- <a href="https://www.flaticon.com/free-icons/video" title="video icons">Video icons created by Freepik - Flaticon</a>
- <a href="https://www.flaticon.com/free-icons/email" title="email icons">Email icons created by Freepik - Flaticon</a>
- <a href="https://www.flaticon.com/free-icons/folder" title="folder icons">Folder icons created by Gajah Mada - Flaticon</a>
- <a href="https://www.flaticon.com/free-icons/pause-play" title="pause play icons">Pause play icons created by Shahid-Mehmood - Flaticon</a>
- <a href="https://www.flaticon.com/free-icons/backspace" title="backspace icons">Backspace icons created by Bharat Icons - Flaticon</a>
- <a href="https://www.flaticon.com/free-icons/calculator" title="calculator icons">Calculator icons created by Pixel perfect - Flaticon</a>
- <a href="https://www.flaticon.com/free-icons/cam" title="cam icons">Cam icons created by Icon Mela - Flaticon</a>
- <a href="https://www.flaticon.com/free-icons/enter" title="enter icons">Enter icons created by Lizel Arina - Flaticon</a>
- <a href="https://www.flaticon.com/free-icons/fast-forward" title="fast forward icons">Fast forward icons created by nawicon - Flaticon</a>
- <a href="https://www.flaticon.com/free-icons/rewind" title="rewind icons">Rewind icons created by nawicon - Flaticon</a>
- <a href="https://www.flaticon.com/free-icons/previous" title="previous icons">Previous icons created by Ralf Schmitzer - Flaticon</a>
- <a href="https://www.flaticon.com/free-icons/keypad" title="keypad icons">Keypad icons created by Google - Flaticon</a>
- <a href="https://www.flaticon.com/free-icons/mute-button" title="mute button icons">Mute button icons created by ZAK - Flaticon</a>
- <a href="https://www.flaticon.com/free-icons/volume-up" title="volume up icons">Volume up icons created by Mayor Icons - Flaticon</a>
- <a href="https://www.flaticon.com/free-icons/volume-down" title="volume down icons">Volume down icons created by Mayor Icons - Flaticon</a>
- <a href="https://www.flaticon.com/free-icons/up" title="up icons">Up icons created by Roundicons Premium - Flaticon</a>
- <a href="https://www.flaticon.com/free-icons/screenshot" title="screenshot icons">Screenshot icons created by Freepik - Flaticon</a>
- <a href="https://www.flaticon.com/free-icons/shift" title="shift icons">Shift icons created by Graphics Plazza - Flaticon</a>
- <a href="https://www.flaticon.com/free-icons/ui" title="ui icons">Ui icons created by Bharat Icons - Flaticon</a>
- <a href="https://www.flaticon.com/free-icons/next" title="next icons">Next icons created by Radhe Icon - Flaticon</a>
- <a href="https://www.flaticon.com/free-icons/intranet" title="intranet icons">Intranet icons created by Freepik - Flaticon</a>
- <a href="https://www.flaticon.com/free-icons/close" title="close icons">Close icons created by Bharat Icons - Flaticon</a>
- <a href="https://www.flaticon.com/free-icons/full-screen" title="full screen icons">Full screen icons created by itim2101 - Flaticon</a>
- <a href="https://www.flaticon.com/free-icons/ui" title="ui icons">Ui icons created by Mike Zuidgeest - Flaticon</a>
- <a href="https://www.flaticon.com/free-icons/go-to-the-top" title="go to the top icons">Go to the top icons created by Cap Cool - Flaticon</a>
- <a href="https://www.flaticon.com/free-icons/capslock" title="capslock icons">Capslock icons created by Roundicons Premium - Flaticon</a>
- <a href="https://www.flaticon.com/free-icons/insert" title="insert icons">Insert icons created by Rahul Kaklotar - Flaticon</a>
- <a href="https://www.flaticon.com/free-icons/automatic" title="automatic icons">Automatic icons created by Freepik - Flaticon</a>
