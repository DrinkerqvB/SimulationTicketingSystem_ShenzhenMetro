



create database financialRecord;

use database financialRecord;

 create table record(
        SerialNumber varchar(50) primary key,       

        OrderDatetime datetime,

        EnterStationDatetime datetime,
        ExitStationDatetime datetime,
        
        StartLine varchar(50),
        StartStation varchar(50),
        EndLine varchar(50),
        EndStation varchar(50),

        TicketType varchar(50),
        TicketID varchar(50)
        TicketNum int,
        SinglePrice float,
        TotalPrice float,

        ModeOfPayment varchar(50)
);

`QString("insert into student values (%1,'%2','%3');").arg(ID).arg(name).arg(birthday);`

insert into `1号线` (`站编号`, `站名`,`车站1`,`车站2`) values (1,`赤湾`,2,3);
select `车站1` from `1号线` where `站名` = '赤湾';
