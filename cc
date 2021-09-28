{//;Начало}
{jset;~tagtext;lang;ru}
{jset;~tagtext;basic.embed.title;Ошибка;t}
{jset;~tagtext;basic.embed.footer.text;Сообщение будет удалено через 15 секунд;t}
{jset;~tagtext;basic.embed.color;{base;{exec;Color};16;10}}
{jset;~tagtext;basic.time;15}
{jset;~tagtext;basic.logging.id;890319560069238804;t}
{jset;~tagtext;basic.logging.token;uTT8hkkokVhAjeTjy8EeT-mUNoI77ef68-opDYCJpat5GyyZIZ6WLk6zlhGx6BV_u3Lw}
{jset;~tagtext;basic.logging.text;{escape;{exec;User} ({userid})
{jstringify;{get;@ccuser{userid}}}
}}

{if;==;{get;@ccusers};;{set;@ccusers;[]}}

{if;==;{get;@ccuser{userid}};;
{jset;@ccuser{userid};dust;10}
{jset;@ccuser{userid};cards;[]}
{jset;@ccuser{userid};warriors;[]}
{push;@ccusers;{userid}}
{jset;@ccuser{userid};monsters.LAB.lvl;0;t}
{set;!@ccuser{userid};{jclean;@ccuser{userid}}}
}

{exec;Log;890319560069238804;uTT8hkkokVhAjeTjy8EeT-mUNoI77ef68-opDYCJpat5GyyZIZ6WLk6zlhGx6BV_u3Lw;Start;{exec;User} ({userid})
{jstringify;{get;@ccuser{userid}}}}

{//;Помощь}
{function;help;
{if;>;{argslength};1;
{switch;{args;1};
battle;
{embed;{embedbuild;color:{exec;Color};
title:Механика боя;
description:В бою участвует две стороны, каждая со своим набором боевых ЧБшников. В наборе не более 5 ЧБшников. Сам бой разделен на раунды, перед каждым раундом происходит распределение соперников. Первый в списке одного бьётся с первым в списке другого. Если число ЧБшников у сторон неравное, то дополнительные ЧБшники помогают в бою тем, для кого нашёлся соперник. При этом помощь идёт с конца списка, примеры возможного распределения:
1+4 vs 1, 2+3 vs 2
1+4 vs 1, 2 vs 2, 3 vs 3
1+5 vs 1, 2+4 vs 2

Затем ЧБшники атакуют друг друга с помощью параметра ⚔️атака. Если 2 ЧБшника атакуют одного противника, то используется атака только одного из них, того, у кого она больше. 
Если атака меньше брони противника, то ничего не происходит, если больше — наносится урон, равный разности ⚔️атаки и 🛡️защиты. Если ❤️здоровье ЧБшника достигает 0, то он умирает и в дальнейших раундах не участвует

В самом конце раунда у всех персонажей уменьшается параметр защиты на 1 или 2 в зависимости от того, сколько у него было противников в этом раунде

Раунды повторяются до смерти всех ЧБшников одной из сторон, но не более 14 раундов. Если никто не смог за это время победить противника, бой считается ничейным}};
["labynkyr","monster"];
{embed;{embedbuild;color:{exec;Color};
title:Механика боя;
description:Дикие лабынкырские черти имеют повышенное здоровье — 80 единиц, однако после боя их здоровье не восстанавливается. Поэтому с первого раза лабынкырского чёрта победить не получится. Вы можете атаковать лабынкырский чертей не чаще раза в час, но учитывайте, что другие пользователи могут добить ослабленных чертей и забрать вашу награду, правильно выбирайте время атаки.

После победы над чертями они на некоторое время озлобятся и будут иметь большую атаку в боях с вами. С каждой новой вашей победой черти будут становиться всё злее и злее, они будут иметь всё большую атаку и на больший период времени.
Первый уровень злобы длится 24 часа и увеличивает атаку чертей до ⚔️12 и ⚔️11. Каждый следующий уровень длится на 24 часа больше и увеличивает дополнительно атаку на ⚔️3

Уровень злобы можно раз в неделю сбросить за 5 пыли с помощью команды ?t cc mask}}
};

{embed;{embedbuild;color:{exec;Color};
title:Помощь;
fields.name:Собери свою коллекцию ЧБшников!;
fields.value:Суть игры в сборе карт с ЧБшниками. Их можно использовать в бою либо просто испытывать счастье от обладания Лабынкыром. При использовании команд вы можете указывать трёхбуквенные коды карт, их названия так, как они указаны в боте, либо их айди. Если название карты содержит пробел, то его следует заключить в "кавычки". 
В <> заключены обязательные аргументы
В [] — необязательные. 
При применении команд использовать <> и [] не нужно
{zws};
fields.name:Основные команды;
fields.value:?t cc daily — получение ежедневной награды
?t cc rand — получение случайной карты (2 пыли) 
?t cc dis <карта> — распыление карты (вы получаете вместо карты количество пыли, равное её рангу)
?t cc dis.all <ранг> — распыление всех карт указанного ранга
?t cc upg <карта> — замена карты на карту рангом выше за пыль (с 1 до 2 — 1 пыль, со 2 до 3 — 2 пыли, с 3 до 4 и с 4 до 5 — 3 пыли)
?t cc sacr — жертвоприношение модераторов для получения лабынкырского чёрта
{zws};
fields.name:Бои;
fields.value:
Узнать информацию о механике боя можно по ?t cc help battle
Узнать больше информации об атаке на лабынкырское чудовище можно по ?t cc help monster
?t cc createparty <карта> ... <карта> либо ?t cc cp — создание группы боевых ЧБшников (от 1 до 5 карт)
?t cc hunt — просмотр целей ежедневной охоты на диких ЧБшников
?t cc hunt <карта> — бой вашей группы боевых ЧБшников против четырёх диких ЧБшников
?t cc monster — охота на больших лабынкырских чёртей для получения 5-20 пыли
?t cc mask — обнуление злобы лабынкырских чертей за 5 пыли
{zws};
fields.name:Взаимодействие с другими игроками;
fields.value:?t cc trade <другой пользователь> <ваша карта> <карта другого пользователя> — для обмена картами
?t cc pvp <пользователь> — бой между двумя игроками. Если эти игроки сегодня ещё не встречались, они оба увеличат свой pvp-рейтинг за него. На 0,5 за поражение, 0,75 за ничью и 1 за победу
{zws};
fields.name:Информационные команды;
fields.value:Если пользователь не указан, то выводится информация о вас
?t cc coll [пользователь] — вывод всех карт коллекции
?t cc party [пользователь] — просмотр группы боевых ЧБшников указанного пользователя. 
?t cc dust [пользователь] — вывод количества пыли
?t cc pvps [пользователь] — список тех, с кем пользователь участвовал в pvp-боях за сегодня
?t cc profile [пользователь] — просмотр всей информации
?t cc card <карта> — просмотр конкретной карточки
?t cc top — топ игроков по pvp-рейтингу}}
}
}

{//;Базовые функции}
{func;_name;{jget;@ccname;{params}}}
{func;_attack;{jget;@ccattack;{params}}}
{func;_defend;{jget;@ccdefend;{params}}}
{func;_type;{jget;@cctype;{params}}}

{//;Проверки с заполнением переменных}
{//;Проверка существования карты и ~card}
{func;_check;{debug;_check}
{set;~index;{indexof;{upper;{jvalues;@ccname}};{upper;{params}}}}
{set;~jkeys;{jkeys;@ccname}}
{if;!=;{jget;@ccn;{upper;{params}}};;{set;~card;{jget;@ccn;{upper;{params}}}};
{if;!=;{get;~index};-1;
{set;~card;{get;~jkeys;{get;~index}}};
{set;~card;{params}}
}}
{exec;E1;==;{jget;@ccname;{get;~card}};;Карты {get;~card} не существует;null}
}

{func;_login;{debug;_login}
{exec;E1;{if;<;{argslength};2;t;{bool;==;{args;1;n};}};{embedbuild;description:Укажите карту};null}
{func._check;{args;1;n}}
}

{//;Проверка существования пользователя и ~userid}
{func;_userid;
{if;{logic;&&;
{bool;!=;{jget;@ccn;{upper;{params}}};};
{logic;!;{bool;includes;{get;@ccid6};{upper;{params}}}}
};
{set;~userid;{jget;@ccn;{upper;{params}}}};
{set;~index;{indexof;{upper;{jvalues;@ccname}};{upper;{params}}}}
{set;~jkeys;{jkeys;@ccname}}
{if;{logic;&&;
{bool;!=;{get;~index};-1};
{logic;!;{bool;includes;{get;@ccid6};{upper;{params}}}}
};
{set;~userid;{get;~jkeys;{get;~index}}};
{set;~userid;{userid;{params}}}
}}
{exec;E1;==;{get;~userid};;Пользователь не найден;null}
}

{func;_user;
{if;==;{argslength};1;
{set;~userid;{userid}};
{func._userid;{args;1;n}}
}
{set;~user;{get;@ccuser{get;~userid}}}
{exec;E1;==;{get;~user};;{params} ещё не играет с нами;null}
}

{//;Проверка существования команды и ~battle1}
{func;_battlecheck;
{exec;E1;==;{jget;~user;battle};;Сначала соберите команду с помощью команды ?t cc createparty;null}
{set;~battle1;{jget;~user;battle}}
{jset;~battle1;user;{username}}

{for;~i;0;<;{length;{jget;~battle1;a}};
{switch;{jget;~battle1;a.{get;~i}.id};{jget;~user;cards};;{exec;Mes;Часть карт из вашего набора боевых ЧБшников больше не в вашей собственности. Пересоберите набор через ?t cc createparty;null}}
}
}


{//;Проверки}
{//;Наличие определенной карты у игрока или его соперника}
{func;_cardlock;{debug;_cardlock}
{switch;{params;0};{jget;{if;>;{paramslength};1;{params;1};~user};cards};;{set;~error;Карта {func._name;{params;0}} недоступна}}
}

{func;_card;{debug;_card}
{switch;{params;0};{jget;{if;>;{paramslength};1;{params;1};~user};cards};;{exec;Mes;Карта {func._name;{params;0}} недоступна;null}}
}

{//;Наличие определенного количества пыли у игрока}
{func;_dustlock;{debug;_dustlock}
{if;<;{jget;~user;dust};{params};{set;~error;Недостаточно пыли. Для этой команды требуется {exec;Number;{params};пыль;пыли;пыли}}}
}

{func;_dust;{debug;_dust}
{exec;E1;<;{jget;~user;dust};{params};Недостаточно пыли. Для этой команды требуется {exec;Number;{params};пыль;пыли;пыли};null}
}

{//;Иные проверки}
{func;_author;{debug;_author}
{exec;E1;!=;{userid};{tagauthor};Этой подкомандой может пользоваться только {exec;User;{tagauthor}};null}
}

{func;_error;{debug;_error}{if;!=;{get;~error};;{exec;Mes;{get;~error};null}}}

{//;Иные функции}
{//;Вывод эмбеда карты}
{func;_embed;{debug;_embed}
{set;~type;{func._type;{params}}}
{embed;{embedbuild;
color:{exec;Color};
title:{func._name;{params}} ⭐{get;~type};
description:⚔️{func._attack;{params}}{space}🛡️{func._defend;{params}}{newline}[ID]({dump;ID: {params}
CODE: {jget;@ccnick;{params}}});
image.url:{jget;@ccavatar;{params}}
}}
}

{//;Изменение количества пыли}
{func;_dust+;{debug;_dust}
{jset;~user;dust;{math;+;{jget;~user;dust};{params}}}
}

{//;Удаление карты}
{func;_dis;{debug;_dis}
{exec;Jdel;{if;>;{paramslength};1;{params;1};~user};cards;{indexof;{jget;{if;>;{paramslength};1;{params;1};~user};cards};{params;0}}}
}

{//;Получение случайной карты}
{func;_rand;{set;~rand;{jkeys;@ccname}}{get;~rand;{rounddown;{math;/;{randint;0;{math;*;{math;-;{length;{get;~rand}};1};1000}};1000}}}}

{func;_random;{debug;_random}
{set;~card;{func._rand}}
{exec;Jpush;~user;cards;{get;~card}}
{func._embed;{get;~card}}
}

{//;Вывод указанного списка карт}
{func;_list;{if;!=;{length;{get;{params}}};0;{for;~i;0;<;{length;{get;{params}}};{set;~card;{get;{params};{get;~i}}}**{math;+;{get;~i};1}.** {func._name;{get;~card}} ⭐{func._type;{get;~card}} ⚔️{func._attack;{get;~card}} 🛡️{func._defend;{get;~card}} ({jget;@ccnick;{get;~card}}){newline}};Отсутствует{newline}}
}

{//;Ежедневные/еженедельные действия}
{if;!=;{jget;@cchunt;time};{time;DD.MM.YYYY};
{jset;@cchunt;time;{time;DD.MM.YYYY}}
{jset;@cchunt;users;[]}
{jset;@cchunt;cards;[]}
{jset;@cchunt;cards.0;{func._rand};t}
{jset;@cchunt;cards.1;{func._rand};t}
{jset;@cchunt;cards.2;{func._rand};t}
{jset;@cchunt;cards.3;{func._rand};t}
{jset;@cchunt;cards.4;{func._rand};t}
{jset;@cchunt;cards.5;{func._rand};t}
{jset;@cchunt;cards.6;{func._rand};t}
}

{//;Команды Фражуза}
{function;import;{debug;_import}
{func._author}
{exec;E1;!=;{guildid};549627903965528075;Импорт возможен только в ЧБ;null}
{lock;write;@ccupd;
{set;@ccid6;["LAB"]}
{jset;@ccname;LAB;Labynkyr}
{jset;@ccattack;LAB;10}
{jset;@ccdefend;LAB;10}
{jset;@cctype;LAB;6}
{jset;@ccavatar;LAB;https://static.wikia.nocookie.net/fantasticbeings/images/d/d2/%D0%9B%D0%B0%D0%B1%D1%8B%D0%BD%D0%BA%D1%8B%D1%80%D1%81%D0%BA%D0%B8%D0%B9_%D1%87%D1%91%D1%80%D1%82.png/revision/latest/scale-to-width-down/340?cb=20130719111803&path-prefix=ru}
{set;~no;{get;@ccid6}}
{set;@ccid5;{filter;~u;{rolemembers;632253362531991572};{switch;{get;~u};{get;~no};f;t}}}
{set;~no;{concat;{get;@ccid5};{get;~no}}}
{set;@ccid4;{filter;~u;{rolemembers;630782579821510657};{switch;{get;~u};{get;~no};f;t}}}
{set;~no;{concat;{get;@ccid4};{get;~no}}}
{set;@ccid3;{filter;~u;{rolemembers;629656780640878595};{switch;{get;~u};{get;~no};f;t}}}
{set;~no;{concat;{get;@ccid3};{get;~no}}}
{set;@ccid2;{filter;~u;{rolemembers;630782454013100033};{switch;{get;~u};{get;~no};f;t}}}
{set;~no;{concat;{get;@ccid2};{get;~no}}}
{set;@ccid1;{filter;~u;{rolemembers;632568887648452618};{switch;{get;~u};{get;~no};f;t}}}
{set;~all;{concat;{get;@ccid1};{get;~no}}}

{foreach;~u;{concat;{get;@ccid5};{get;@ccid4};{get;@ccid3};{get;@ccid2};{get;@ccid1}};
{jset;@ccavatar;{get;~u};{useravatar;{get;~u}}}
{jset;@cctype;{get;~u};{if;includes;{get;@ccid6};{get;~u};6;
{if;includes;{get;@ccid5};{get;~u};5;
{if;includes;{get;@ccid4};{get;~u};4;
{if;includes;{get;@ccid3};{get;~u};3;
{if;includes;{get;@ccid2};{get;~u};2;
{if;includes;{get;@ccid1};{get;~u};1;{jget;@cctype;{get;~u}}
}}}}}};t}

{set;~name;{username;{get;~u}}}
{if;{logic;||;
{logic;!;{logic;||;
{regextest;{get;~name};/[^0-9а-яА-ЯёЁa-zA-Z\- ]/};
{logic;&&;
{regextest;{get;~name};/[а-яА-ЯёЁ]/};
{regextest;{get;~name};/[a-zA-Z]/}
}}};
{bool;==;{jget;@ccname;{get;~u}};}
};
{jset;@ccname;{get;~u};{get;~name}}
}
{set;~defend;{math;+;{func._type;{get;~u}};7}}
{if;!=;{math;+;0{jget;@ccattack;{get;~u}};0{jget;@ccdefend;{get;~u}}};{get;~defend};
{set;~attack;{randint;1;{math;-;{get;~defend};1}}}
{set;~defend;{math;-;{get;~defend};{get;~attack}}}
{jset;@ccattack;{get;~u};{get;~attack};t}
{jset;@ccdefend;{get;~u};{get;~defend};t}
}}
Готово
}}

{function;decancer;
{func._author}
{lock;write;@ccupd;
{set;~cards;{jkeys;@ccname}}
{set;~names;[]}
{foreach;~card;~cards;
{set;~name;{func._name;{get;~card}}}
{if;{regextest;{get;~name};/[@#₽&%$€£^{}§|~…<>.,\_!?+*’"«»„“=:\[\]\/\\\(\)]/};
{set;~name;{regexreplace;{get;~name};/[@#₽&%$€£^{}§|~…<>.,\_!?+*’"«»„“=:\[\]\/\\\(\)]/g;{space}}}
}
{if;{regextest;{get;~name};/[^0-9а-яА-ЯёЁa-zA-Z\- ]/};
{set;~name;{exec;Translate;{get;~name}}}
{if;==;{get;~name};`Cannot read property '0' of undefined`;{output;Команда временно недоступна, повторите попытку позже}{return}}
}
{if;{regextest;{get;~name};/[^0-9а-яА-ЯёЁa-zA-Z\- ]/};
{set;~name;{exec;decancer;{get;~name}}}
}
{if;{logic;&&;
{regextest;{get;~name};/[а-яА-ЯёЁ]/};
{regextest;{get;~name};/[a-zA-Z]/}
};
{set;~name;{exec;decancer;{get;~name}}}
}
{if;{regextest;{get;~name};/[^0-9а-яА-ЯёЁa-zA-Z\- ]/};
{set;~name;{regexreplace;{get;~name};/[^0-9а-яА-ЯёЁa-zA-Z\- ]/g;}}
}
{set;~name;{trim;{get;~name}}}
{if;==;{get;~name};;{set;~name;Noname}}
{while;includes;{get;~names};{upper;{get;~name}};
{set;~name;{get;~name}1}
{void;{increment;~i}}
}
{push;~names;{upper;{get;~name}}}
{jset;@ccname;{get;~card};{get;~name}}
}
Готово
}}

{function;num;
{func._author}
{set;~cards;{jkeys;@ccname}}
{exec;E1;<;{argslength};2;{embedbuild;description:Укажите сотню, для которой производится обсчёт};null}
{exec;E1;!=;{parseint;{args;1}};{args;1};{embedbuild;description:Укажите сотню, для которой производится обсчёт};null}
{exec;E1;>;{math;*;{args;1};100};{length;{get;~cards}};{embedbuild;description:Этой сотни не существует};null}

{lock;write;@ccupd;
{foreach;~card;{slice;~cards;{math;*;{args;1};100};{math;*;{math;+;{args;1};1};100}};
{jset;@ccnum;{get;~card};{exec;Same;{jget;@ccname;{get;~card}}}}
}
Готово
}}

{function;nick;
{func._author}
{set;~cards;{jkeys;@ccname}}
{set;~nicks;[]}
{set;@ccnick;}
{set;@ccn;}
{foreach;~card;~cards;
{set;~nick;{substring;{regexreplace;{func._name;{get;~card}};/[ \-]/;};0;3}}
{set;~i;1}
{set;~nick;{upper;{get;~nick}}}
{while;includes;{get;~nicks};{get;~nick};
{set;~nick;{substring;{get;~nick};0;3}{increment;~i}}
}
{push;~nicks;{get;~nick}}
{jset;@ccnick;{get;~card};{get;~nick}}
{jset;@ccn;{get;~nick};{get;~card}}
}
Готово
}

{function;dust+;
{func._author}
{if;>;{argslength};2;{func._userid;{args;2;n}};{set;~userid;{userid}}}
{exec;E1;!=;{parseint;{args;1}};{args;1};Укажите изменение количества пыли;null}
{lock;write;@ccuser;
{set;~user;{get;!@ccuser{get;~userid}}}
{func._dust+;{args;1;n}}
{set;!@ccuser{get;~userid};{get;~user}}
}
{exec;cc;dust;{get;~userid}}
}

{function;card+;
{func._author}
{if;>;{argslength};2;{func._userid;{args;2;n}};{set;~userid;{userid}}}
{func._check;{args;1}}
{lock;write;@ccuser;
{set;~user;{get;!@ccuser{get;~userid}}}
{exec;Jpush;~user;cards;{get;~card}}
{set;!@ccuser{get;~userid};{get;~user}}
}
{exec;cc;coll;{get;~userid}}
}

{function;monster+;
{func._author}
{if;>;{argslength};1;{func._userid;{args}};{set;~userid;{userid}}}
{lock;write;@ccuser;
{set;~user;{get;!@ccuser{get;~userid}}}
{jset;~user;monstertime;0}
{set;!@ccuser{get;~userid};{get;~user}}
}
Готово
}

{function;hunt+;
{func._author}
{if;>;{argslength};1;{func._userid;{args}};{set;~userid;{userid}}}
{lock;write;@ccuser;
{set;~user;{get;!@ccuser{get;~userid}}}
{jset;~user;hunt;0}
{set;!@ccuser{get;~userid};{get;~user}}
}
Готово
}

{function;daily+;
{func._author}
{if;>;{argslength};1;{func._userid;{args}};{set;~userid;{userid}}}
{lock;write;@ccuser;
{set;~user;{get;!@ccuser{get;~userid}}}
{jset;~user;daily;0}
{set;!@ccuser{get;~userid};{get;~user}}
}
Готово
}

{function;labynkyr+;
{func._author}
{if;>;{argslength};1;{func._userid;{args}};{set;~userid;{userid}}}
{lock;write;@ccuser;
{set;~user;{get;!@ccuser{get;~userid}}}
{jset;~user;monsters.LAB.time;0}
{set;!@ccuser{get;~userid};{get;~user}}
}
Готово
}

{function;mask+;
{func._author}
{if;>;{argslength};1;{func._userid;{args}};{set;~userid;{userid}}}
{lock;write;@ccuser;
{set;~user;{get;!@ccuser{get;~userid}}}
{jset;~user;mask;0}
{set;!@ccuser{get;~userid};{get;~user}}
}
Готово
}

{function;see;
{func._author}
{func._user}
{jstringify;{get;~user}}
}

{//;Информационные команды}
{function;profile;
{func._user}
{if;!=;{jget;~user;warriors};;{set;~warriors;{jget;~user;warriors}}}
{set;~cards;{jget;~user;cards}}
{embed;{embedbuild;color:{exec;Color};
title:{username;{get;~userid}};
fields.name:Информация;
fields.value:**Количество пыли:** {jget;~user;dust}
**Ежедневная награда:** {if;==;{jget;~user;daily};{time;DD.MM.YYYY};через {exec;Tconvert;{math;-;{time;X;{math;+;{time;DD};1};DD};{time;X}};t};доступна}
**PVP-рейтинг:** {math;+;0{jget;@ccpvp;{get;~userid}};0}
**Охота на диких ЧБшников:** {if;==;{jget;~user;hunt};{time;DD.MM.YYYY};через {exec;Tconvert;{math;-;{time;X;{math;+;{time;DD};1};DD};{time;X}};t};доступна}
**Охота на лабынкырского чёрта:** {set;~time;{math;-;{math;+;3600;0{jget;~user;monstertime}};{time;X}}}{if;>;{get;~time};0;через {exec;Tconvert;{get;~time};t};доступна}
**Злоба лабынкырских чертей:** {set;~time;{math;-;{math;+;{math;*;86400;{jget;~user;monsters.LAB.lvl}};0{jget;~user;monsters.LAB.time}};{time;X}}}{if;>;{get;~time};0;пройдёт через {exec;Tconvert;{get;~time};t};отсутствует}
**Уровень злобы:** {jget;~user;monsters.LAB.lvl}
**Сброс злобы:** {if;==;{jget;~user;mask};{time;W.YYYY};через {exec;Tconvert;{math;-;{time;X;{math;+;{time;W};1};W};{time;X}};t};доступен}
{zws};
fields.name:Коллекция ЧБшников;
fields.value:{func._list;~cards}{zws};
fields.name:Команда боевых ЧБшников;
fields.value:{func._list;~warriors}
}}
}

{function;dust;
{func._user}
{embed;{embedbuild;
color:{exec;Color};
title:{username;{get;~userid}};
description:Количество пыли: {jget;@ccuser{get;~userid};dust}
}}
}

{function;coll;
{func._user}
{set;~cards;{jget;~user;cards}}
{embed;{embedbuild;
color:{exec;Color};
title:Коллекция ЧБшников {username;{get;~userid}};
description:{func._list;~cards}
}}
}

{function;party;
{func._user}
{if;!=;{jget;~user;warriors};;{set;~warriors;{jget;~user;warriors}}}
{embed;{embedbuild;
color:{exec;Color};
title:Набор боевых ЧБшников {username;{get;~userid}};
description:{func._list;~warriors}
}}
}

{function;pvps;
{func._user}
{void;{addreact;{messageid};{exec;loading;5}}}
{embed;{embedbuild;
color:{exec;Color};
title:Бои {username;{get;~userid}} за {time;DD.MM.YYYY};
description:{set;~b;{join;{map;~b;{filter;~b;{jkeys;@ccpvpwas};
{if;includes;{split;{get;~b};-};{get;~userid};{bool;==;{time;DD.MM.YYYY};{jget;@ccpvpwas;{get;~b}}};f}
};{set;~c;{split;{get;~b};-}}{if;==;{get;~c;0};{get;~userid};{exec;User;{get;~c;1}};{exec;User;{get;~c;0}}}};{newline}}}{if;==;{get;~b};;Отсутствуют;{get;~b}}
}}
{delete}
}

{function;card;
{func._login}
{func._embed;{get;~card}}
}

{function;top;
{set;~i;0}
{embed;{embedbuild;title:Топ по pvp-рейтингу;
color:{exec;Color};
description:{join;{map;~j;
{jsort;{map;~u;{jkeys;@ccpvp};{lb}"id":"{get;~u}","p":"{jget;@ccpvp;{get;~u}}"{rb}};p;t};**{increment;~i}.** {username;{jget;~j;id}} — {jget;~j;p}};{newline}}
}}
}

{function;health;
{embed;{embedbuild;title:Здоровье монстров;
color:{exec;Color};
description:Лабынкырские черти: {if;==;{jget;@ccmonster;LAB.a};;❤️80 и ❤️80;❤️{jget;@ccmonster;LAB.a.0.hp}{if;>;{length;{jget;@ccmonster;LAB.a}};1;{space}и ❤️{jget;@ccmonster;LAB.a.1.hp}}}
}}
}

{//;Изменение состава коллекции}
{function;random;
{set;~user;{get;@ccuser{userid}}}
{func._dust;2}
{lock;write;@ccuser;
{set;~user;{get;!@ccuser{userid}}}
{func._dustlock;3}

{if;==;{get;~error};;
{func._dust+;-2}
Успех. Осталось пыли: {jget;~user;dust}
{func._random}
{set;!@ccuser{userid};{get;~user}}
}}
{func._error}
}


{function;daily;
{set;~user;{get;@ccuser{userid}}}
{exec;E1;==;{jget;~user;daily};{time;DD.MM.YYYY};Сегодня вы уже брали карту. До возможности взять карту ещё раз осталось {jset;~tagtext;lang;ru}{exec;Tconvert;{math;-;{time;X;{math;+;{time;DD};1};DD};{time;X}}};null}
{lock;write;@ccuser;
{set;~user;{get;!@ccuser{userid}}}
{if;==;{jget;~user;daily};{time;DD.MM.YYYY};{set;~error;Сегодня вы уже брали карту. До возможности взять карту ещё раз осталось {jset;~tagtext;lang;ru}{exec;Tconvert;{math;-;{time;X;{math;+;{time;DD};1};DD};{time;X}}}}}

{if;==;{get;~error};;
{jset;~user;daily;{time;DD.MM.YYYY}}
{func._random}
{set;!@ccuser{userid};{get;~user}}
}}
{func._error}
}


{function;dis;
{func._login}
{set;~user;{get;@ccuser{userid}}}
{func._card;{get;~card}}

{lock;write;@ccuser;
{set;~user;{get;!@ccuser{userid}}}
{func._cardlock;{get;~card}}

{if;==;{get;~error};;
{func._dis;{get;~card}}
{func._dust+;{func._type;{get;~card}}}
{set;!@ccuser{userid};{get;~user}}
Успех. Всего пыли: {jget;~user;dust}
}}
{func._error}
}

{function;dis.all;
{exec;E1;{if;<;{argslength};2;t;{switch;{args;1};[1...7];f;t}};Укажите ранг распыляемых карт;null}
{exec;Send;Распылены следующие карты:;n}
{lock;write;@ccuser;
{set;~user;{get;!@ccuser{userid}}}
{foreach;~card;{jget;~user;cards};
{if;==;{func._type;{get;~card}};{args;1};
{exec;Send;{func._name;{get;~card}};n}
{func._dis;{get;~card}}
{func._dust+;{args;1}}
}}
Успех. Всего пыли: {jget;~user;dust}
{embed;{embedbuild;color:{exec;Color};title:Готово;description:{exec;Output}}}
{set;!@ccuser{userid};{get;~user}}
}
}

{function;upgrade;
{func._login}
{set;~type;{func._type;{get;~card}}}
{exec;E1;==;{get;~type};5;Дальше карты апгрейдить нельзя;null}
{set;~cost;{switch;{get;~type};1;1;2;2;["3","4"];3}}
{set;~user;{get;!@ccuser{userid}}}
{func._card;{get;~card}}
{func._dust;{get;~cost}}

{lock;write;@ccuser;
{set;~user;{get;!@ccuser{userid}}}
{func._cardlock;{get;~card}}
{func._dustlock;{get;~cost}}

{if;==;{get;~error};;
{func._dis;{get;~card}}
{func._dust+;-{get;~cost}}
{set;~card;{apply;randchoose;{get;@ccid{math;+;1;{get;~type}}}}}
{exec;Jpush;~user;cards;{get;~card}}
Успех. Осталось пыли: {jget;~user;dust}
{func._embed;{get;~card}}
{set;!@ccuser{userid};{get;~user}}
}}
{func._error}
}

{function;sacrifice;
{set;~user;{get;@ccuser{userid}}}
{foreach;~card;@ccid5;
{func._card;{get;~card}}
}
{lock;write;@ccuser;
{set;~user;{get;!@ccuser{userid}}}
{foreach;~card;@ccid5;
{func._cardlock;{get;~card}}
{func._dis;{get;~card}}
}
{if;==;{get;~error};;
{exec;Jpush;~user;cards;LAB}
{set;!@ccuser{userid};{get;~user}}
}}
{func._error}
{func._embed;LAB}
}

{//;Боевая система}
{func;_battle;
{void;{addreact;{messageid};{exec;loading;5}}}
{set;~i;0}
{inject;{lb}embedbuild{semi}
color:{exec;Color}{semi}
title:Бой{semi}
{while;{logic;&&;
{bool;!=;{length;{jget;~battle1;a}};0};
{bool;!=;{length;{jget;~battle2;a}};0};
{bool;!=;{get;~i};14}
};
fields.name:Раунд {increment;~i}{semi}
fields.value:
{for;~j;0;<;{min;{length;{jget;~battle1;a}};{length;{jget;~battle2;a}}};
{set;~+;}
{set;~def1;}
{set;~def2;}
{set;~hp1;}
{set;~hp2;}
{set;~battle1+;{get;~battle1}}
{set;~battle2+;{get;~battle2}}

{set;~J;{math;-;{length;{jget;~battle1;a}};{get;~j};1}}
{if;>=;{get;~J};{length;{jget;~battle2;a}};{set;~+;1};
{set;~J;{math;-;{length;{jget;~battle2;a}};{get;~j};1}}
{if;>=;{get;~J};{length;{jget;~battle1;a}};{set;~+;2}}
}

{set;~hp-;{math;-;
{if;==;{get;~+};1;
{max;{jget;~battle1;a.{get;~j}.attack};{jget;~battle1;a.{get;~J}.attack}};
{jget;~battle1;a.{get;~j}.attack}
};
{jget;~battle2;a.{get;~j}.defend}
}}
{set;~def-;{if;==;{get;~+};1;2;1}}

{if;>;{jget;~battle2;a.{get;~j}.defend};0;
{jset;~battle2;a.{get;~j}.defend;
{max;0;{math;-;{jget;~battle2;a.{get;~j}.defend};{get;~def-}}};t}
{set;~def2;{space}(-{get;~def-})}
}
{if;>;{get;~hp-};0;
{jset;~battle2;a.{get;~j}.hp;{math;-;{jget;~battle2;a.{get;~j}.hp};{get;~hp-}};t}
{set;~hp2;{space}(-{get;~hp-}){if;<=;{jget;~battle2;a.{get;~j}.hp};0;{space}☠️}}
}

{set;~hp-;{math;-;
{if;==;{get;~+};2;
{max;{jget;~battle2;a.{get;~j}.attack};{jget;~battle2;a.{get;~J}.attack}};
{jget;~battle2;a.{get;~j}.attack}
};
{jget;~battle1;a.{get;~j}.defend}
}}
{set;~def-;{if;==;{get;~+};2;2;1}}

{if;>;{jget;~battle1;a.{get;~j}.defend};0;
{jset;~battle1;a.{get;~j}.defend;
{max;0;{math;-;{jget;~battle1;a.{get;~j}.defend};{get;~def-}}};t}
{set;~def1;{space}(-{get;~def-})}
}
{if;>;{get;~hp-};0;
{jset;~battle1;a.{get;~j}.hp;{math;-;{jget;~battle1;a.{get;~j}.hp};{get;~hp-}};t}
{set;~hp1;{space}(-{get;~hp-}){if;<=;{jget;~battle1;a.{get;~j}.hp};0;{space}☠️}}
}

{exec;Send;⚔️{jget;~battle1+;a.{get;~j}.attack};s}
{exec;Send;🛡️{jget;~battle1+;a.{get;~j}.defend}{get;~def1};s} 
{exec;Send;❤️{jget;~battle1+;a.{get;~j}.hp}{get;~hp1};s}
{exec;Send;**{jget;~battle1;a.{get;~j}.name}**;s}
{exec;Send;vs.;s}
{exec;Send;⚔️{jget;~battle2+;a.{get;~j}.attack};s}
{exec;Send;🛡️{jget;~battle2+;a.{get;~j}.defend}{get;~def2};s} 
{exec;Send;❤️{jget;~battle2+;a.{get;~j}.hp}{get;~hp2};s}
{exec;Send;**{jget;~battle2;a.{get;~j}.name}**;n}

{switch;{get;~+};
1;
{exec;Send;⚔️{jget;~battle1;a.{get;~J}.attack};s}
{exec;Send;🛡️{jget;~battle1;a.{get;~J}.defend};s}
{exec;Send;❤️{jget;~battle1;a.{get;~J}.hp};s}
{exec;Send;*{jget;~battle1;a.{get;~J}.name}*;n};
2;
{set;~n;26.5}
{exec;Incv;~n;{jget;@ccnum;{jget;~battle1;a.{get;~j}.id}}}
{exec;Incv;~n;{if;==;{get;~def1};;0;{switch;{get;~def-};
1;7.8;
[3,7];8.4;
[2,5];8.45;
[6,9];8.55;
8;8.6;
4;8.7;
0;8.8;
11;9.6;
[13,17];10.2;
[12,15];10.25;
[16,19];10.35;
18;10.4;
14;10.5;
10;10.6}}}
{exec;Incv;~n;{if;==;{get;~hp1};;0;{switch;{get;~hp-};
1;7.8;
[3,7];8.4;
[2,5];8.45;
[6,9];8.55;
8;8.6;
4;8.7;
0;8.8;
11;9.6;
[13,17];10.2;
[12,15,21];10.25;
[16,19];10.35;
18;10.4;
14;10.5;
10;10.6;
20;11.25}}}
{if;<=;{jget;~battle1;a.{get;~j}.hp};0;{exec;Incv;~n;6.5}}

{exec;Incv;~n;{switch;{jget;~battle1+;a.{get;~j}.attack};
1;1.8;
[3,7];2.4;
[2,5];2.45;
[6,9];2.55;
8;2.6;
4;2.7;
0;2.8;
11;3.6;
[13,17];4.2;
[12,15];4.25;
[16,19];4.35;
18;4.4;
14;4.5;
10;4.6}}
{exec;Incv;~n;{switch;{jget;~battle1+;a.{get;~j}.defend};
1;1.8;
[3,7];2.4;
[2,5];2.45;
[6,9];2.55;
8;2.6;
4;2.7;
0;2.8;
11;3.6;
[13,17];4.2;
[12,15];4.25;
[16,19];4.35;
18;4.4;
14;4.5;
10;4.6}}
{exec;Incv;~n;{switch;{jget;~battle1+;a.{get;~j}.hp};
1;1.8;
[3,7];2.4;
[2,5];2.45;
[6,9];2.55;
8;2.6;
4;2.7;
0;2.8;
11;3.6;
[13,17];4.2;
[12,15];4.25;
[16,19];4.35;
18;4.4;
14;4.5;
10;4.6}}
{set;~Send;{get;~Send}{space;{round;{get;~n}}}}
{exec;Send;⚔️{jget;~battle2;a.{get;~J}.attack};s}
{exec;Send;🛡️{jget;~battle2;a.{get;~J}.defend};s}
{exec;Send;❤️{jget;~battle2;a.{get;~J}.hp};s}
{exec;Send;*{jget;~battle2;a.{get;~J}.name}*;n}
}
}

{jset;~battle1;a;{filter;~c;{jget;~battle1;a};{bool;>;{jget;~c;hp};0}};t}
{jset;~battle2;a;{filter;~c;{jget;~battle2;a};{bool;>;{jget;~c;hp};0}};t}
{exec;Output}{if;{logic;&&;
{bool;!=;{length;{jget;~battle1;a}};0};
{bool;!=;{length;{jget;~battle2;a}};0};
{bool;!=;{get;~i};14}
};{zws}}{semi}
}
description:{if;==;{length;{jget;~battle1;a}};{length;{jget;~battle2;a}};Ничья{set;~result;0};{switch;0;{length;{jget;~battle1;a}};Победил {set;~result;2}{jget;~battle2;user}.;{length;{jget;~battle2;a}};Победил {jget;~battle1;user}{set;~result;1};Ничья{set;~result;0}}}
{rb}}
{delete}
}

{//;Взаимодействие с другими игроками}
{function;trade;
{exec;E1;<;{argslength};4;t;Укажите обмениваемые карты и пользователя, с которым вы хотите поменяться;null}
{func._userid;{args;1}}
{set;~user1;{get;@ccuser{userid}}}
{set;~user2;{get;@ccuser{get;~userid}}}
{exec;E1;==;{get;~user2};;{params} ещё не играет с нами;null}

{func._check;{args;2}}
{set;~card1;{get;~card}}
{func._check;{args;3}}
{set;~card2;{get;~card}}

{set;~type1;{func._type;{get;~card1}}}
{set;~type2;{func._type;{get;~card2}}}
{exec;E1;!=;{get;~type1};{get;~type2};Обменивать можно только равные по рангу карты;null}

{func._card;{get;~card1};~user1}
{func._card;{get;~card2};~user2}

{set;~mid;{output;{usermention;{get;~userid}}, не хотели бы вы отдать {func._name;{get;~card2}} и получить {func._name;{get;~card1}}?}}
{addreact;{get;~mid};👍}
{set;~r;{waitreaction;{get;~mid};{get;~userid};👍}}
{if;==;{get;~r};`Wait timed out after 60000`;{edit;{get;~mid};{embedbuild;color:{exec;Color};title:Ошибка;description:Время ожидания истекло}}{return}}

{lock;write;@ccuser;
{set;~user1;{get;!@ccuser{userid}}}
{set;~user2;{get;!@ccuser{get;~userid}}}
{func._cardlock;{get;~card1};~user1}
{func._cardlock;{get;~card2};~user2}

{if;==;{get;~error};;
{func._dis;{get;~card1};~user1}
{exec;Jpush;~user1;cards;{get;~card2}}
{func._dis;{get;~card2};~user2}
{exec;Jpush;~user2;cards;{get;~card1}}
{set;!@ccuser{userid};{get;~user1}}
{set;!@ccuser{get;~userid};{get;~user2}}
}}
{if;==;{get;~error};;
{edit;{get;~mid};Успешно};
{edit;{get;~mid};;{embedbuild;title:Ошибка;description:{get;~error}}}
}
}

{function;pvp;
{exec;E1;<;{argslength};2;Укажите, с кем вы хотите биться;null}
{set;~user1;{get;@ccuser{userid}}}
{func._userid;{args;1;n}}
{set;~user2;{get;@ccuser{get;~userid}}}

{set;~user;{get;~user1}}
{func._battlecheck}

{exec;E1;==;{jget;~user2;battle};;У вашего оппонента нет группы боевых ЧБшников;null}
{set;~battle2;{jget;~user2;battle}}
{jset;~battle2;user;{username;{get;~userid}}}

{for;~i;0;<;{length;{jget;~battle2;a}};
{switch;{jget;~battle2;a.{get;~i}.id};{jget;~user2;cards};;{exec;Mes;Часть карт из набора боевых ЧБшников вашего оппонента больше не в его собственности. Ему необходимо пересобрать набор через ?t cc createparty;null}}
}

{set;~mid;{output;{usermention;{get;~userid}}, не хотели бы вы начать бой с {username}?}}
{addreact;{get;~mid};👍}
{set;~r;{waitreaction;{get;~mid};{get;~userid};👍}}
{if;==;{get;~r};`Wait timed out after 60000`;{edit;{get;~mid};{embedbuild;color:{exec;Color};title:Ошибка;description:Время ожидания истекло}}{return}}


{edit;{get;~mid};Бой скоро начнётся}
{set;~battle;{func._battle}}

{lock;write;@ccpvp;
{set;~p;{bool;!=;{jget;!@ccpvpwas;{userid}-{get;~userid}};{time;DD.MM.YYYY}}}
{edit;{get;~mid};{if;{get;~p};За бой начислен рейтинг;За бой не начислен рейтинг, так как соревнующиеся уже встречались сегодня};{get;~battle}}
{if;{get;~p};
{jset;!@ccpvpwas;{userid}-{get;~userid};{time;DD.MM.YYYY}}
{switch;{get;~result};
0;
{jset;!@ccpvp;{userid};{math;+;0{jget;!@ccpvp;{userid}};0.75};t}
{jset;!@ccpvp;{get;~userid};{math;+;0{jget;!@ccpvp;{get;~userid}};0.75};t};
1;
{jset;!@ccpvp;{userid};{math;+;0{jget;!@ccpvp;{userid}};1};t}
{jset;!@ccpvp;{get;~userid};{math;+;0{jget;!@ccpvp;{get;~userid}};0.5};t};
2;
{jset;!@ccpvp;{userid};{math;+;0{jget;!@ccpvp;{userid}};0.5};t}
{jset;!@ccpvp;{get;~userid};{math;+;0{jget;!@ccpvp;{get;~userid}};1};t}
}}}
}

{//;Бои}
{function;createparty;
{set;~user;{get;@ccuser{userid}}}
{set;~battle;{j;{"a":[]}}}
{jset;~battle;user;{username}}
{exec;E1;{if;<;{argslength};2;t;{bool;==;{args;1;n};}};Укажите хотя бы одну карту;null}
{exec;E1;>;{argslength};6;Нельзя указывать более 5 карт;null}
{set;~ar;{slice;{argsarray};1}}
{set;~arid;[]}
{for;~i;0;<;{length;{get;~ar}};
{func._check;{get;~ar;{get;~i}}}
{func._card;{get;~card}}
{switch;{get;~card};{get;~arid};{exec;Mes;Только дикие ЧБшники сбиваются в стаи. В вашей группе боевых ЧБшников все должны быть уникальны;null}}
{push;~arid;{get;~card}}
{jset;~battle;a.{get;~i}.id;{get;~card};t}
{jset;~battle;a.{get;~i}.name;{func._name;{get;~card}};t}
{jset;~battle;a.{get;~i}.attack;{func._attack;{get;~card}};t}
{jset;~battle;a.{get;~i}.defend;{func._defend;{get;~card}};t}
{jset;~battle;a.{get;~i}.hp;10;t}
}

{lock;write;@ccuser;
{set;~user;{get;!@ccuser{userid}}}
{jset;~user;battle;{get;~battle};t}
{jset;~user;warriors;{get;~arid};t}
{set;!@ccuser{userid};{jclean;~user}}
}
{set;~battle;{map;~c;{jget;~battle;a};{jget;~c;id}}}
{embed;{embedbuild;
color:{exec;Color};
title:Набор боевых ЧБшников {username};
description:{func._list;~arid}
}}
}

{function;hunt;
{if;==;{argslength};1;
{set;~cards;{jget;@cchunt;cards}}
{embed;{embedbuild;
color:{exec;Color};
title:Охота на диких ЧБшников;
description:В лесах ЧБ обитают дикие ЧБшники. Вы можете неограниченно биться с ними, если создадите группу боевых ЧБшников, однако в целях охраны дикой природы Администрация ЧБ разрешает забирать себе в коллекцию после победы только одного ЧБшника в сутки на человека и только из сегодняшнего списка охоты;
fields.name:Список охоты {time;DD.MM.YYYY};
fields.value:{func._list;~cards};
footer.text:?t cc createparty <карта> ... <карта> (до 5 карт) — создание группы боевых ЧБшников 
?t cc hunt <карта> — начало охоты (внимательно выбирайте цель, вы сможете забрать сегодня только одного ЧБшника)
}};
{set;~user;{get;@ccuser{userid}}}
{func._battlecheck}
{func._login}
{set;~battle2;{lb}"a":[{lb}"id":"{get;~card}","name":"{jget;@ccname;{get;~card}}","attack":"{jget;@ccattack;{get;~card}}","defend":"{jget;@ccdefend;{get;~card}}","hp":"10"{rb},{lb}"id":"{get;~card}","name":"{jget;@ccname;{get;~card}}","attack":"{jget;@ccattack;{get;~card}}","defend":"{jget;@ccdefend;{get;~card}}","hp":"10"{rb},{lb}"id":"{get;~card}","name":"{jget;@ccname;{get;~card}}","attack":"{jget;@ccattack;{get;~card}}","defend":"{jget;@ccdefend;{get;~card}}","hp":"10"{rb},{lb}"id":"{get;~card}","name":"{jget;@ccname;{get;~card}}","attack":"{jget;@ccattack;{get;~card}}","defend":"{jget;@ccdefend;{get;~card}}","hp":"10"{rb}]{rb}}
{jset;~battle2;user;Дикий {jget;@ccname;{get;~card}}}
{embed;{func._battle}}
{if;==;{get;~result};1;{switch;{get;~card};{jget;@cchunt;cards};{if;!=;{jget;~user;hunt};{time;DD.MM.YYYY};Так как сегодня вы впервые победили цель из списка охоты, дикий {func._name;{get;~card}} присоединяется к вам
{lock;write;@ccuser;
{set;~user;{get;!@ccuser{userid}}}
{exec;Jpush;~user;cards;{get;~card}}
{jset;~user;hunt;{time;DD.MM.YYYY}}
{set;!@ccuser{userid};{get;~user}}
}
}}}
}}


{function;monster;
{set;~user;{get;@ccuser{userid}}}
{func._battlecheck}
{lock;write;@ccuser;
{set;~user;{get;!@ccuser{userid}}}
{set;~time;{math;-;{math;+;3600;0{jget;~user;monstertime}};{time;X}}}
{if;>;{get;~time};0;{set;~error;{embedbuild;title:Не так быстро;description:Вам нужно восстановиться перед боем, подождите {jset;~tagtext;lang;ru}{exec;Tconvert;{get;~time};}}}}

{if;==;{get;~error};;
{jset;~user;monstertime;{time;X}}
{set;!@ccuser{userid};{get;~user}}
}}
{if;!=;{get;~error};;{exec;Mes;{get;~error};null}}
{set;~card;LAB}
{set;~+;{bool;>;{math;+;{math;*;86400;{jget;~user;monsters.LAB.lvl}};0{jget;~user;monsters.LAB.time}};{time;X}}}
{if;==;{jget;@ccmonster;{get;~card}.a};;{jset;@ccmonster;{get;~card}.a;[{lb}"id":"{get;~card}","name":"{jget;@ccname;{get;~card}}","attack":"{jget;@ccattack;{get;~card}}","defend":"{jget;@ccdefend;{get;~card}}","hp":"80"{rb},{lb}"id":"{get;~card}","name":"{jget;@ccname;{get;~card}}","attack":"{jget;@ccattack;{get;~card}}","defend":"{jget;@ccdefend;{get;~card}}","hp":"80"{rb}];t}}
{jset;~battle2;a;{jget;@ccmonster;{get;~card}.a}}
{jset;~battle2;a.0.defend;{jget;@ccdefend;{get;~card}};t}
{if;==;{length;{jget;~battle2;a}};2;{jset;~battle2;a.1.defend;{jget;@ccdefend;{get;~card}};t}}
{if;{get;~+};
{jset;~battle2;a.0.attack;{math;+;{math;*;3;{jget;~user;monsters.LAB.lvl}};9};t}
{if;==;{length;{jget;~battle2;a}};2;{jset;~battle2;a.1.attack;{math;+;{math;*;3;{jget;~user;monsters.LAB.lvl}};8};t}};
{jset;~battle2;a.0.attack;{jget;@ccattack;{get;~card}};t}
{if;==;{length;{jget;~battle2;a}};2;{jset;~battle2;a.1.attack;{jget;@ccattack;{get;~card}};t}}
}
{jset;~battle2;user;Дикий {jget;@ccname;{get;~card}}}
{embed;{func._battle}}
{if;!=;{length;{jget;~battle2;a}};0;
Вы смогли ослабить лабынкырского чёрта. Подождите час перед повторной атакой
{jset;@ccmonster;{get;~card}.a;{jget;~battle2;a};t};
{jset;@ccmonster;{get;~card}.a;;t}
{set;~number;{randint;5;20}}
При обыске пещеры мёртвых лабынкырских чертов вы нашли {get;~number} пыли. Но черти сообщили о вас своим товарищам и теперь они злы. В течение некоторого времени черти при столкновении с вами будут сильнее
{lock;write;@ccuser;
{set;~user;{get;!@ccuser{userid}}}
{jset;~user;monsters.LAB.time;{time;X};t}
{jset;~user;monsters.LAB.lvl;{math;+;0{jget;~user;monsters.LAB.lvl};1};t}
{func._dust+;{get;~number}}
{set;!@ccuser{userid};{get;~user}}
}
}}

{function;mask;
{set;~user;{get;@ccuser{userid}}}
{func._dust;5}
{exec;E1;==;{jget;~user;mask};{time;W.YYYY};На этой неделе вы уже сбрасывали уровень злобы. Подождите {exec;Tconvert;{math;-;{time;X;{math;+;{time;W};1};W};{time;X}};t};null}
{set;~time;{math;-;{math;+;{math;*;86400;{jget;~user;monsters.LAB.lvl}};0{jget;~user;monsters.LAB.time}};{time;X}}}
{exec;E1;>;{get;~time};0;Невозможно сбросить уровень злобы, когда на вас ещё злятся. Подождите {exec;Tconvert;{get;~time};t};null}

{lock;write;@ccuser;
{set;~user;{get;!@ccuser{userid}}}
{func._dustlock;5}
{if;==;{jget;~user;mask};{time;W.YYYY};{set;~error;На этой неделе вы уже сбрасывали уровень злобы. Подождите {exec;Tconvert;{math;-;{time;X;{math;+;{time;W};1};W};{time;X}};t}}}

{if;==;{get;~error};;
{func._dust+;-5}
{jset;~user;monsters.LAB.lvl;0}
{jset;~user;mask;{time;W.YYYY}}
{set;!@ccuser{userid};{get;~user}}
}}
{func._error}
Готово
}

{if;==;{args};;{func.help}}
{switch;{args;0};help;{func.help};
["import","imp"];{func.import};
["decancer","dec"];{func.decancer};
num;{func.num};
nick;{func.nick};
card;{func.card};
profile;{func.profile};
dust;{func.dust};
["random","rand"];{func.random};
dis;{func.dis};
dis.all;{func.dis.all};
coll;{func.coll};
daily;{func.daily};
["evolve","upgrade","upg"];{func.upgrade};
trade;{func.trade};
["createparty","cp"];{func.createparty};
party;{func.party};
["hunt","pve"];{func.hunt};
["labynkyr","monster"];{func.monster};
["sacr","sacrifice"];{func.sacrifice};
pvp;{func.pvp};
dust+;{func.dust+};
card+;{func.card+};
mask;{func.mask};
pvps;{func.pvps};
top;{func.top};
monster+;{func.monster+};
hunt+;{func.hunt+};
daily+;{func.daily+};
labynkyr+;{func.labynkyr+};
mask+;{func.mask+};
see;{func.see};
health;{func.health}
}

{exec;Log;890319560069238804;uTT8hkkokVhAjeTjy8EeT-mUNoI77ef68-opDYCJpat5GyyZIZ6WLk6zlhGx6BV_u3Lw;End;
{get;~userid}
{get;~cards}
{get;~cost}
{get;~type}
{jstringify;{get;~user}}}
