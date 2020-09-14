-- phpMyAdmin SQL Dump
-- version 2.7.0-pl2
-- http://www.phpmyadmin.net
-- 
-- Servidor: oraclepr.uco.es
-- Tiempo de generación: 03-01-2020 a las 21:45:17
-- Versión del servidor: 5.1.73
-- Versión de PHP: 5.3.3
-- 
-- Base de datos: `i72lulem`
-- 

-- --------------------------------------------------------

-- 
-- Estructura de tabla para la tabla `BUSINESSES`
-- 

CREATE TABLE `BUSINESSES` (
  `cif` varchar(9) NOT NULL,
  `mail` varchar(25) NOT NULL,
  `password` varchar(25) NOT NULL,
  `name` varchar(25) NOT NULL,
  `short_description` varchar(25) DEFAULT 'Ninguna',
  `website` varchar(100) DEFAULT 'Ninguna',
  `description` varchar(500) DEFAULT 'Ninguna',
  `searching` varchar(500) DEFAULT 'Ninguna',
  `offering` varchar(500) DEFAULT 'Ninguna',
  `job_offer` varchar(500) DEFAULT 'Ninguna',
  PRIMARY KEY (`cif`),
  UNIQUE KEY `mail` (`mail`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Businesses registered';

-- 
-- Volcar la base de datos para la tabla `BUSINESSES`
-- 


-- --------------------------------------------------------

-- 
-- Estructura de tabla para la tabla `FOLLOWS`
-- 

CREATE TABLE `FOLLOWS` (
  `follower` varchar(25) NOT NULL,
  `following` varchar(25) NOT NULL,
  PRIMARY KEY (`follower`,`following`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Follows information (follower-following)';

-- 
-- Volcar la base de datos para la tabla `FOLLOWS`
-- 


-- --------------------------------------------------------

-- 
-- Estructura de tabla para la tabla `GROUPS`
-- 

CREATE TABLE `GROUPS` (
  `group_id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(25) DEFAULT 'Nuevo grupo',
  `description` varchar(25) DEFAULT 'Ninguna',
  PRIMARY KEY (`group_id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Groups registered' AUTO_INCREMENT=1 ;

-- 
-- Volcar la base de datos para la tabla `GROUPS`
-- 


-- --------------------------------------------------------

-- 
-- Estructura de tabla para la tabla `IN_GROUP`
-- 

CREATE TABLE `IN_GROUP` (
  `user_mail` varchar(25) NOT NULL,
  `group_id` int(11) NOT NULL,
  PRIMARY KEY (`user_mail`,`group_id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- 
-- Volcar la base de datos para la tabla `IN_GROUP`
-- 


-- --------------------------------------------------------

-- 
-- Estructura de tabla para la tabla `LIKES`
-- 

CREATE TABLE `LIKES` (
  `user_mail` varchar(25) NOT NULL,
  `post_id` int(11) NOT NULL,
  PRIMARY KEY (`user_mail`,`post_id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Like information (user-post)';

-- 
-- Volcar la base de datos para la tabla `LIKES`
-- 


-- --------------------------------------------------------

-- 
-- Estructura de tabla para la tabla `POSTS`
-- 

CREATE TABLE `POSTS` (
  `post_id` int(11) NOT NULL AUTO_INCREMENT,
  `title` varchar(25) NOT NULL,
  `author` varchar(50) NOT NULL,
  `date` date NOT NULL,
  `nlikes` int(11) NOT NULL,
  PRIMARY KEY (`post_id`),
  KEY `author` (`author`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Posts registered' AUTO_INCREMENT=1 ;

-- 
-- Volcar la base de datos para la tabla `POSTS`
-- 


-- --------------------------------------------------------

-- 
-- Estructura de tabla para la tabla `SAVED_POSTS`
-- 

CREATE TABLE `SAVED_POSTS` (
  `user_mail` varchar(25) NOT NULL,
  `post_id` int(11) NOT NULL,
  PRIMARY KEY (`user_mail`,`post_id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Saved posts (user-post)';

-- 
-- Volcar la base de datos para la tabla `SAVED_POSTS`
-- 


-- --------------------------------------------------------

-- 
-- Estructura de tabla para la tabla `USERS`
-- 

CREATE TABLE `USERS` (
  `mail` varchar(25) NOT NULL,
  `password` varchar(25) NOT NULL,
  `first` varchar(25) NOT NULL,
  `last` varchar(25) NOT NULL,
  `birth_date` date NOT NULL,
  `affiliation` varchar(25) DEFAULT 'Ninguna',
  `job` varchar(25) DEFAULT 'Ninguno',
  `picture` varchar(50) DEFAULT '../../img/usuario.png',
  `interests` varchar(255) DEFAULT 'Ninguno',
  `background` varchar(255) DEFAULT 'Ninguno',
  PRIMARY KEY (`mail`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Users registered';

-- 
-- Volcar la base de datos para la tabla `USERS`
-- 

INSERT INTO `USERS` VALUES ('alex@mail.com', '1234', 'Alex', 'TesT', '2020-01-14', 'Ninguna', 'Ninguno', '../../img/usuario.png', 'Ninguno', 'Ninguno');

-- --------------------------------------------------------

-- 
-- Estructura de tabla para la tabla `WORK_REQUEST`
-- 

CREATE TABLE `WORK_REQUEST` (
  `user_mail` varchar(25) NOT NULL,
  `business_cif` varchar(9) NOT NULL,
  PRIMARY KEY (`user_mail`,`business_cif`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Work request (user-offer_business)';

-- 
-- Volcar la base de datos para la tabla `WORK_REQUEST`
-- 

-- Ejemplos de insercion
--INSERT INTO `USERS` VALUES (1, 'Angola', 'Juan', 15);
--INSERT INTO `USERS` VALUES (2, 'Becerra', 'Francisco', 23);
--INSERT INTO `USERS` VALUES (3, 'Carmona', 'José', 43);
--INSERT INTO `USERS` VALUES (4, 'Davide', 'Giovanni', 31);
--INSERT INTO `USERS` VALUES (5, 'Esteban', 'Pedro', 24);
--INSERT INTO `User` VALUES (6, 'Ferrero', 'Manuel', 56);
