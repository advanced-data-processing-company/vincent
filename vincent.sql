
/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;


-- Dumping database structure for vincent
DROP DATABASE IF EXISTS `vincent`;
CREATE DATABASE IF NOT EXISTS `vincent` /*!40100 DEFAULT CHARACTER SET utf8 */;
USE `vincent`;

-- Dumping structure for table vincent.capital
DROP TABLE IF EXISTS `capital`;
CREATE TABLE IF NOT EXISTS `capital` (
  `id` int(11) DEFAULT NULL,
  `number` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='资金表';

-- Dumping data for table vincent.capital: ~0 rows (approximately)
DELETE FROM `capital`;
/*!40000 ALTER TABLE `capital` DISABLE KEYS */;
/*!40000 ALTER TABLE `capital` ENABLE KEYS */;

-- Dumping structure for table vincent.cargo
DROP TABLE IF EXISTS `cargo`;
CREATE TABLE IF NOT EXISTS `cargo` (
  `id` int(11) DEFAULT NULL,
  `description` varchar(50) DEFAULT NULL COMMENT '货物描述',
  `name` varchar(50) DEFAULT NULL COMMENT '货物名称',
  `produce_area` varchar(50) DEFAULT NULL COMMENT '源产地',
  `price` double DEFAULT NULL COMMENT '价格',
  `unit` varchar(50) DEFAULT NULL COMMENT '价格单位',
  `relative_person` json DEFAULT NULL COMMENT '与货物相关的人员',
  `relative_geo_posotion` json DEFAULT NULL COMMENT '货物地理位置信息'
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='货物信息表';

-- Dumping data for table vincent.cargo: ~0 rows (approximately)
DELETE FROM `cargo`;
/*!40000 ALTER TABLE `cargo` DISABLE KEYS */;
/*!40000 ALTER TABLE `cargo` ENABLE KEYS */;

-- Dumping structure for table vincent.geo_position
DROP TABLE IF EXISTS `geo_position`;
CREATE TABLE IF NOT EXISTS `geo_position` (
  `id` int(11) DEFAULT NULL,
  `name` varchar(50) DEFAULT NULL,
  `latitude` double DEFAULT NULL,
  `longitude` double DEFAULT NULL,
  `area` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='地理位置信息表';

-- Dumping data for table vincent.geo_position: ~0 rows (approximately)
DELETE FROM `geo_position`;
/*!40000 ALTER TABLE `geo_position` DISABLE KEYS */;
/*!40000 ALTER TABLE `geo_position` ENABLE KEYS */;

-- Dumping structure for table vincent.group
DROP TABLE IF EXISTS `group`;
CREATE TABLE IF NOT EXISTS `group` (
  `id` int(11) DEFAULT NULL,
  `name` varchar(50) DEFAULT NULL,
  `description` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='用户组';

-- Dumping data for table vincent.group: ~0 rows (approximately)
DELETE FROM `group`;
/*!40000 ALTER TABLE `group` DISABLE KEYS */;
/*!40000 ALTER TABLE `group` ENABLE KEYS */;

-- Dumping structure for table vincent.group_priviledge
DROP TABLE IF EXISTS `group_priviledge`;
CREATE TABLE IF NOT EXISTS `group_priviledge` (
  `id` int(11) DEFAULT NULL,
  `group_id` int(11) DEFAULT NULL,
  `priviledge_id` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='组和权限关联表';

-- Dumping data for table vincent.group_priviledge: ~0 rows (approximately)
DELETE FROM `group_priviledge`;
/*!40000 ALTER TABLE `group_priviledge` DISABLE KEYS */;
/*!40000 ALTER TABLE `group_priviledge` ENABLE KEYS */;

-- Dumping structure for table vincent.person
DROP TABLE IF EXISTS `person`;
CREATE TABLE IF NOT EXISTS `person` (
  `id` int(11) DEFAULT NULL,
  `name` varchar(50) DEFAULT NULL,
  `gender` int(11) DEFAULT NULL,
  `brith_date` date DEFAULT NULL,
  `address` varchar(50) DEFAULT NULL,
  `phone_number` varchar(50) DEFAULT NULL,
  `role` json DEFAULT NULL,
  `group` json DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='人员信息表';

-- Dumping data for table vincent.person: ~0 rows (approximately)
DELETE FROM `person`;
/*!40000 ALTER TABLE `person` DISABLE KEYS */;
/*!40000 ALTER TABLE `person` ENABLE KEYS */;

-- Dumping structure for table vincent.priviledge
DROP TABLE IF EXISTS `priviledge`;
CREATE TABLE IF NOT EXISTS `priviledge` (
  `id` int(11) DEFAULT NULL,
  `description` varchar(50) DEFAULT NULL,
  `priviledge` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='权限表';

-- Dumping data for table vincent.priviledge: ~0 rows (approximately)
DELETE FROM `priviledge`;
/*!40000 ALTER TABLE `priviledge` DISABLE KEYS */;
/*!40000 ALTER TABLE `priviledge` ENABLE KEYS */;

-- Dumping structure for table vincent.purchase_order
DROP TABLE IF EXISTS `purchase_order`;
CREATE TABLE IF NOT EXISTS `purchase_order` (
  `id` int(11) DEFAULT NULL,
  `name` varchar(50) DEFAULT NULL,
  `generate_time` date DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='订单信息表';

-- Dumping data for table vincent.purchase_order: ~0 rows (approximately)
DELETE FROM `purchase_order`;
/*!40000 ALTER TABLE `purchase_order` DISABLE KEYS */;
/*!40000 ALTER TABLE `purchase_order` ENABLE KEYS */;

-- Dumping structure for table vincent.purchase_order_cargo_relation
DROP TABLE IF EXISTS `purchase_order_cargo_relation`;
CREATE TABLE IF NOT EXISTS `purchase_order_cargo_relation` (
  `id` int(11) DEFAULT NULL,
  `cargo_id` int(11) DEFAULT NULL,
  `purchase_order_id` int(11) DEFAULT NULL,
  `cargo_number` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='订单货物关联表';

-- Dumping data for table vincent.purchase_order_cargo_relation: ~0 rows (approximately)
DELETE FROM `purchase_order_cargo_relation`;
/*!40000 ALTER TABLE `purchase_order_cargo_relation` DISABLE KEYS */;
/*!40000 ALTER TABLE `purchase_order_cargo_relation` ENABLE KEYS */;

-- Dumping structure for table vincent.role
DROP TABLE IF EXISTS `role`;
CREATE TABLE IF NOT EXISTS `role` (
  `id` int(11) DEFAULT NULL,
  `name` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='角色表';

-- Dumping data for table vincent.role: ~0 rows (approximately)
DELETE FROM `role`;
/*!40000 ALTER TABLE `role` DISABLE KEYS */;
/*!40000 ALTER TABLE `role` ENABLE KEYS */;

-- Dumping structure for table vincent.sales_return_order
DROP TABLE IF EXISTS `sales_return_order`;
CREATE TABLE IF NOT EXISTS `sales_return_order` (
  `id` int(11) DEFAULT NULL,
  `cargo_id` varchar(50) DEFAULT NULL,
  `purchase_order_id` int(11) DEFAULT NULL,
  `number` int(11) DEFAULT NULL,
  `time` date DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='退货单';

-- Dumping data for table vincent.sales_return_order: ~0 rows (approximately)
DELETE FROM `sales_return_order`;
/*!40000 ALTER TABLE `sales_return_order` DISABLE KEYS */;
/*!40000 ALTER TABLE `sales_return_order` ENABLE KEYS */;

-- Dumping structure for table vincent.warehouse
DROP TABLE IF EXISTS `warehouse`;
CREATE TABLE IF NOT EXISTS `warehouse` (
  `id` int(11) DEFAULT NULL,
  `address` varchar(50) DEFAULT NULL COMMENT '仓库地址',
  `capacity` double DEFAULT NULL COMMENT '仓库容量',
  `used` double DEFAULT NULL COMMENT '已使用容量',
  `expire_time` date DEFAULT NULL COMMENT '到期日期',
  `keeper` json DEFAULT NULL COMMENT '仓库管理员'
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='仓库信息表';

-- Dumping data for table vincent.warehouse: ~0 rows (approximately)
DELETE FROM `warehouse`;
/*!40000 ALTER TABLE `warehouse` DISABLE KEYS */;
/*!40000 ALTER TABLE `warehouse` ENABLE KEYS */;

-- Dumping structure for table vincent.warehouse_entry_order
DROP TABLE IF EXISTS `warehouse_entry_order`;
CREATE TABLE IF NOT EXISTS `warehouse_entry_order` (
  `id` int(11) DEFAULT NULL,
  `cargo_id` int(11) DEFAULT NULL,
  `order_id` int(11) DEFAULT NULL,
  `cargo_number` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='仓库入库单';

-- Dumping data for table vincent.warehouse_entry_order: ~0 rows (approximately)
DELETE FROM `warehouse_entry_order`;
/*!40000 ALTER TABLE `warehouse_entry_order` DISABLE KEYS */;
/*!40000 ALTER TABLE `warehouse_entry_order` ENABLE KEYS */;

-- Dumping structure for table vincent.log
DROP TABLE IF EXISTS `log`;
CREATE TABLE IF NOT EXISTS `log` (
  `id` int(11) DEFAULT NULL,
  `module_name` varchar(50) DEFAULT NULL COMMENT '模块名称',
  `log_level` int(5) DEFAULT 0 COMMENT '日志级别',
  `log_date` date DEFAULT NULL COMMENT '日志生成时间',
  `log_content` json DEFAULT NULL COMMENT '日志内容'
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='日志记录表';

-- Dumping data for table vincent.log: ~0 rows (approximately)
DELETE FROM `log`;
/*!40000 ALTER TABLE `log` DISABLE KEYS */;
/*!40000 ALTER TABLE `log` ENABLE KEYS */;

/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IF(@OLD_FOREIGN_KEY_CHECKS IS NULL, 1, @OLD_FOREIGN_KEY_CHECKS) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
