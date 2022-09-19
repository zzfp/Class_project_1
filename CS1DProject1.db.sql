BEGIN TRANSACTION;
CREATE TABLE IF NOT EXISTS "foodSheet" (
	"field1"	TEXT,
	"field2"	TEXT,
	"field3"	TEXT
);
CREATE TABLE IF NOT EXISTS "distanceSheet" (
	"field1"	TEXT,
	"field2"	TEXT,
	"field3"	INTEGER
);
CREATE TABLE IF NOT EXISTS "newFoodsSheet" (
	"field1"	TEXT,
	"field2"	TEXT,
	"field3"	TEXT
);
CREATE TABLE IF NOT EXISTS "newDistanceSheet" (
	"field1"	TEXT,
	"field2"	TEXT,
	"field3"	INTEGER
);
INSERT INTO "foodSheet" VALUES ('City','Traditional Food Item','Cost');
INSERT INTO "foodSheet" VALUES ('Amsterdam',NULL,NULL);
INSERT INTO "foodSheet" VALUES (NULL,'Stroopwafel','$5.88');
INSERT INTO "foodSheet" VALUES (NULL,'Thick Dutch fries','$3.21');
INSERT INTO "foodSheet" VALUES (NULL,'Kibbeling','$8.65');
INSERT INTO "foodSheet" VALUES ('Berlin',NULL,NULL);
INSERT INTO "foodSheet" VALUES (NULL,'Pretzels','$4.44');
INSERT INTO "foodSheet" VALUES (NULL,'Apfelstrudel','$6.25');
INSERT INTO "foodSheet" VALUES (NULL,'Berliner Pfannkuche','$8.23');
INSERT INTO "foodSheet" VALUES (NULL,'Schnitzel','$9.99');
INSERT INTO "foodSheet" VALUES ('Brussels',NULL,NULL);
INSERT INTO "foodSheet" VALUES (NULL,'Waterzooi','$6.48');
INSERT INTO "foodSheet" VALUES (NULL,'Luikse Siroop','$4.98');
INSERT INTO "foodSheet" VALUES (NULL,'Mosselen-friet','$4.45');
INSERT INTO "foodSheet" VALUES (NULL,'Speculoos','$2.79');
INSERT INTO "foodSheet" VALUES ('Budapest',NULL,NULL);
INSERT INTO "foodSheet" VALUES (NULL,'goulash','$8.47');
INSERT INTO "foodSheet" VALUES (NULL,'Stuffed cabbage','$6.99');
INSERT INTO "foodSheet" VALUES (NULL,'Smoked meat','$12.99');
INSERT INTO "foodSheet" VALUES (NULL,'Dobos torta','$2.79');
INSERT INTO "foodSheet" VALUES ('Hamburg',NULL,NULL);
INSERT INTO "foodSheet" VALUES (NULL,'Hamburger Hummersuppe','$6.46');
INSERT INTO "foodSheet" VALUES (NULL,'Knackwurst','$9.99');
INSERT INTO "foodSheet" VALUES (NULL,'Krabbentoast','$6.92');
INSERT INTO "foodSheet" VALUES (NULL,'Franzbrötchen','$12.74');
INSERT INTO "foodSheet" VALUES ('Lisbon',NULL,NULL);
INSERT INTO "foodSheet" VALUES (NULL,'Bacalhau','$5.49');
INSERT INTO "foodSheet" VALUES (NULL,'Caldeirada','$7.63');
INSERT INTO "foodSheet" VALUES (NULL,'Alcatra','$18.66');
INSERT INTO "foodSheet" VALUES ('London',NULL,NULL);
INSERT INTO "foodSheet" VALUES (NULL,'Yorkshire Pudding','$3.49');
INSERT INTO "foodSheet" VALUES (NULL,'Bangers and Mash','$6.63');
INSERT INTO "foodSheet" VALUES (NULL,'Sticky Toffee Pudding','$5.66');
INSERT INTO "foodSheet" VALUES ('Madrid',NULL,NULL);
INSERT INTO "foodSheet" VALUES (NULL,'Bocata de calamares','$6.96');
INSERT INTO "foodSheet" VALUES (NULL,'Oreja a la plancha','$11.85');
INSERT INTO "foodSheet" VALUES (NULL,'Caracoles a la madrileña','$6.94');
INSERT INTO "foodSheet" VALUES ('Paris',NULL,NULL);
INSERT INTO "foodSheet" VALUES (NULL,'Caramels','$4.76');
INSERT INTO "foodSheet" VALUES (NULL,'Bordier Butter','$5.65');
INSERT INTO "foodSheet" VALUES (NULL,'Baguette','$4.99');
INSERT INTO "foodSheet" VALUES (NULL,'Pain au Chocolat','$4.69');
INSERT INTO "foodSheet" VALUES ('Prague',NULL,NULL);
INSERT INTO "foodSheet" VALUES (NULL,'Beef steak tartare','$18.96');
INSERT INTO "foodSheet" VALUES (NULL,'Kulajda','$6.89');
INSERT INTO "foodSheet" VALUES (NULL,'Svickova','$5.98');
INSERT INTO "foodSheet" VALUES (NULL,'Roast duck','$14.69');
INSERT INTO "foodSheet" VALUES ('Rome',NULL,NULL);
INSERT INTO "foodSheet" VALUES (NULL,'Spaghetti alla Carbonara','$6.88');
INSERT INTO "foodSheet" VALUES (NULL,'Bruschetta','$4.77');
INSERT INTO "foodSheet" VALUES (NULL,'Scaloppine','$12.99');
INSERT INTO "foodSheet" VALUES (NULL,'Rigatoni con la Pajata','$8.79');
INSERT INTO "foodSheet" VALUES (NULL,'Carciofi alla giudia','$15.99');
INSERT INTO "distanceSheet" VALUES ('Prague','Amsterdam',878);
INSERT INTO "distanceSheet" VALUES ('Prague','Berlin',349);
INSERT INTO "distanceSheet" VALUES ('Prague','Brussels',898);
INSERT INTO "distanceSheet" VALUES ('Prague','Budapest',525);
INSERT INTO "distanceSheet" VALUES ('Prague','Hamburg',640);
INSERT INTO "distanceSheet" VALUES ('Prague','Lisbon',2707);
INSERT INTO "distanceSheet" VALUES ('Prague','London',1265);
INSERT INTO "distanceSheet" VALUES ('Prague','Madrid',2312);
INSERT INTO "distanceSheet" VALUES ('Prague','Paris',1030);
INSERT INTO "distanceSheet" VALUES ('Prague','Rome',1303);
INSERT INTO "distanceSheet" VALUES ('Rome','Amsterdam',1647);
INSERT INTO "distanceSheet" VALUES ('Rome','Berlin',1502);
INSERT INTO "distanceSheet" VALUES ('Rome','Brussels',1483);
INSERT INTO "distanceSheet" VALUES ('Rome','Budapest',1274);
INSERT INTO "distanceSheet" VALUES ('Rome','Hamburg',1658);
INSERT INTO "distanceSheet" VALUES ('Rome','Lisbon',2510);
INSERT INTO "distanceSheet" VALUES ('Rome','London',1866);
INSERT INTO "distanceSheet" VALUES ('Rome','Madrid',1951);
INSERT INTO "distanceSheet" VALUES ('Rome','Paris',1442);
INSERT INTO "distanceSheet" VALUES ('Rome','Prague',1303);
INSERT INTO "newFoodsSheet" VALUES ('Stockholm',NULL,NULL);
INSERT INTO "newFoodsSheet" VALUES (NULL,'Raggmunk','$6.75');
INSERT INTO "newFoodsSheet" VALUES (NULL,'Gravad lax','$13.76');
INSERT INTO "newFoodsSheet" VALUES (NULL,'husmanskost','$7.98');
INSERT INTO "newFoodsSheet" VALUES ('Vienna',NULL,NULL);
INSERT INTO "newFoodsSheet" VALUES (NULL,'Wiener Schnitzel','$4.94');
INSERT INTO "newFoodsSheet" VALUES (NULL,'Kaiserschmarrn','$7.53');
INSERT INTO "newFoodsSheet" VALUES (NULL,'Sachertorte','$5.85');
INSERT INTO "newDistanceSheet" VALUES ('Stockholm','Hamburg',1079);
INSERT INTO "newDistanceSheet" VALUES ('Stockholm','Lisbon',3610);
INSERT INTO "newDistanceSheet" VALUES ('Stockholm','London',1902);
INSERT INTO "newDistanceSheet" VALUES ('Stockholm','Madrid',3141);
INSERT INTO "newDistanceSheet" VALUES ('Stockholm','Paris',1885);
INSERT INTO "newDistanceSheet" VALUES ('Stockholm','Prague',1428);
INSERT INTO "newDistanceSheet" VALUES ('Stockholm','Rome',2546);
INSERT INTO "newDistanceSheet" VALUES ('Stockholm','Vienna',1758);
INSERT INTO "newDistanceSheet" VALUES ('Vienna','Amsterdam',1147);
INSERT INTO "newDistanceSheet" VALUES ('Vienna','Berlin',640);
INSERT INTO "newDistanceSheet" VALUES ('Vienna','Brussels',1104);
INSERT INTO "newDistanceSheet" VALUES ('Vienna','Budapest',243);
INSERT INTO "newDistanceSheet" VALUES ('Vienna','Hamburg',930);
INSERT INTO "newDistanceSheet" VALUES ('Vienna','Lisbon',2867);
INSERT INTO "newDistanceSheet" VALUES ('Vienna','London',1461);
INSERT INTO "newDistanceSheet" VALUES ('Vienna','Madrid',2401);
INSERT INTO "newDistanceSheet" VALUES ('Vienna','Paris',1236);
INSERT INTO "newDistanceSheet" VALUES ('Vienna','Prague',331);
INSERT INTO "newDistanceSheet" VALUES ('Vienna','Rome',1120);
INSERT INTO "newDistanceSheet" VALUES ('Vienna','Stockholm',1758);
COMMIT;
