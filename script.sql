create table course(
    id integer primary key
);
create table groupe
(   id integer primary key,
    name varchar(1)
);
create table inscrit(
    id integer primary key,
    nom varchar(255) not null,
    idGroupe integer,
    foreign key (idGroupe) references groupe(id)
);
create table special(
    id integer primary key,
    nom varchar(255) not null,
    idCourse integer,
    foreign key (idCourse) references course(id)
);
create table temps(
    id integer primary key,
    idInscrit integer,
    idSpecial integer,
    mn int,
    s int,
    ms int,
    foreign key (idInscrit) references inscrit(id),
    foreign key (idSpecial) REFERENCES special(id)
);

insert into groupe values(null,'A');
insert into groupe values(null,'B');
insert into groupe values(null,'C');

insert into inscrit values(null,'Concurrent 1',2);
insert into inscrit values(null,'Concurrent 2',1);
insert into inscrit values(null,'Concurrent 3',1);
insert into inscrit values(null,'Concurrent 4',2);
insert into inscrit values(null,'Concurrent 5',2);
insert into inscrit values(null,'Concurrent 6',1);
insert into inscrit values(null,'Verstappen',null);
insert into inscrit values(null,'Leclerc',null);

create view v_inscritGroupe as 
select groupe.id as groupe_id,
name as groupe_name,
inscrit.id as inscrit_id,
nom as inscrit_nom
from groupe
join inscrit on groupe.id = inscrit.idGroupe;

create view v_inscritGroupeTemps as
select 
groupe_name,
groupe_id,
inscrit_nom,
idInscrit,
temps.id as id_temps,
idSpecial,
mn,
s,
ms
from
temps join v_inscritGroupe on inscrit_id=temps.idInscrit;

create view v_tempsComplet as
select 
groupe_name,
groupe_id,
inscrit_nom,
idInscrit,
id_temps,
idSpecial,
mn,
s,
ms,
idCourse
from v_inscritGroupeTemps join special
on idSpecial= special.id;

delete from temps;
delete from special;
delete from course;
delete from inscrit;
delete from groupe;

PRAGMA foreign_keys = ON;

delete:
PRAGMA writable_schema = 1;
DELETE FROM sqlite_master WHERE type IN ('table', 'index', 'trigger');
PRAGMA writable_schema = 0;
VACUUM;
PRAGMA integrity_check;

INSERT INTO temps (id,idInscrit, idSpecial, mn, s, ms) VALUES (null,1,2,2,24,10) ON CONFLICT (idInscrit, idSpecial) DO UPDATE SET mn = excluded.mn, s = excluded.s, ms = excluded.ms

CREATE VIEW v_resultatParCourse AS
SELECT 
    c.id AS course_id, 
    i.id AS inscrit_id,
    i.nom AS inscrit_name,
    SUM(t.mn) AS total_minutes, 
    SUM(t.s) AS total_seconds, 
    SUM(t.ms) AS total_milliseconds,
    ROW_NUMBER() OVER (ORDER BY SUM(t.mn) + SUM(t.s) / 60 + SUM(t.ms) / 60000) AS ranking
FROM 
    temps t
JOIN 
    inscrit i ON t.idInscrit = i.id
JOIN 
    special s ON t.idSpecial = s.id
JOIN 
    course c ON s.idCourse = c.id
GROUP BY 
    c.id, i.id;

CREATE VIEW v_resultatParGroupe AS
SELECT 
    c.id AS course_id, 
    g.name AS groupe_name,
    g.id AS groupe_id,
    i.id AS inscrit_id, 
    i.nom AS inscrit_name,
    SUM(t.mn) AS total_minutes, 
    SUM(t.s) AS total_seconds, 
    SUM(t.ms) AS total_milliseconds,
    ROW_NUMBER() OVER (PARTITION BY g.id ORDER BY SUM(t.mn) + SUM(t.s) / 60 + SUM(t.ms) / 60000) AS ranking
FROM 
    temps t
JOIN 
    inscrit i ON t.idInscrit = i.id
JOIN 
    special s ON t.idSpecial = s.id
JOIN 
    course c ON s.idCourse = c.id
JOIN 
    groupe g ON i.idGroupe = g.id
GROUP BY 
    c.id, i.id;