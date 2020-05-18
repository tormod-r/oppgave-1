
CREATE TABLE `data` (
  `id` int(11) NOT NULL,
  `event` timestamp NOT NULL DEFAULT current_timestamp(),
  `temperature` varchar(10) NOT NULL,
  `humidity` varchar(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

ALTER TABLE `data`
  ADD PRIMARY KEY (`id`);

ALTER TABLE `data`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=1;



