# Tables

base tables are *person*, compound table are *purchase order* and *salse*

## bills and records

### purchase_bill

### warehouse_entry_bill

### reject_bill

## Goods

## Capital

## Person

## Warehouse

### role

- id
- type int for custom/providers/salse

## group  purpose of this

- id
- description

## purchase_cargo

- id
- cargo_id
- amount
- total_cost

## warehouse_warrant

- id
- purchase_id
- warehouse_id
- cargo_amount

## sales_return

- id
- cargo_id
- purchase_id
- return_amount

## role_group

- id
- role_id
- group_id

## person

- id
- name
- gender
- birth_date
- address
- phone_number

## person_role

- id
- person_id
- role_id

## priviledge

- id
- description

## group_priviledge

- id
- group_id
- priviledge_id

## geo_position TODO complete this

-id

## warehouse

- id
- address
- capacity
- used
- expire_date

## warehouse_keeper

- id
- warehouse_id
- person_id

## capital TODO complete this

- id

## order_bill

- id
- create_time

## goods

- id
- description:string
- produce_area
- price
- unit

## goods_person

- id
- goods_id
- person_id:list

## goods_geo

- id
- goods_id
- geo_id
