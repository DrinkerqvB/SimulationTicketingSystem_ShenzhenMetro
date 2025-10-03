
create database ordinaryTickets;
create database businessTickets;

use database ordinaryTickets;
use database businessTickets;

 create or replace table `1号线`(
        `站编号` int,
        `站名`   varchar(50) primary key,
         `车站1` int not null,
         `车站1` int not null
 );



create database financialRecord;

use database financialRecord;

 create or replace table record(
        OrderNumber varchar(50) primary key,       

        PayDate date,
        PayTime time,

        BeginFrom varchar(50),
        EndTo varchar(50),

        TicketType varchar(50),
        TicketQuantity int,
        UnitPrice float,
        TotalPrice float,

        ModeOfPayment varchar(50)
);

`QString("insert into student values (%1,'%2','%3');").arg(ID).arg(name).arg(birthday);`

insert into `1号线` (`站编号`, `站名`,`车站1`,`车站2`) values (1,`赤湾`,2,3);
select `车站1` from `1号线` where `站名` = '赤湾';
