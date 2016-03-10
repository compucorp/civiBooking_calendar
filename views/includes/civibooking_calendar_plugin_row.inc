<?php

class civibooking_calendar_plugin_row extends calendar_plugin_row {

    function init(&$view, &$display, $options = NULL) {
        parent::init($view, $display, $options);
    }

    function explode_values($event)
    {
        if (isset($event->row->civicrm_booking_end_date)) {
            $rows = array();

            $date_info = $this->date_argument->view->date_info;
            $item_start_date = $event->date_start;

            $test = $event->row->civicrm_booking_end_date;

            $item_end_date = date('Y-m-d', $test);
            watchdog('civibooking', print_r($item_end_date, true));



            $to_zone = $event->to_zone;
            $db_tz = $event->db_tz;
            $granularity = $event->granularity;
            $increment = $event->increment;

            // Now that we have an 'entity' for each view result, we need
            // to remove anything outside the view date range,
            // and possibly create additional nodes so that we have a 'node'
            // for each day that this item occupies in this view.
            $now = max($date_info->min_zone_string, $item_start_date->format(DATE_FORMAT_DATE));
            $to = $item_end_date;

            $next = new DateObject($now . ' 00:00:00', $date_info->display_timezone);
            if ($date_info->display_timezone_name != $to_zone) {
                // Make $start and $end (derived from $node) use the timezone $to_zone, just as the original dates do.
                date_timezone_set($next, timezone_open($to_zone));
            }
            if (empty($to) || $now > $to) {
                $to = $now;
            }
            // $now and $next are midnight (in display timezone) on the first day where node will occur.
            // $to is midnight on the last day where node will occur.
            // All three were limited by the min-max date range of the view.
            $pos = 0;
            while (!empty($now) && $now <= $to) {
                $entity = clone($event);

                // Get start and end of current day.
                $start = $next->format(DATE_FORMAT_DATETIME);
                date_modify($next, '+1 day');
                date_modify($next, '-1 second');
                $end = $next->format(DATE_FORMAT_DATETIME);

                // Get start and end of item, formatted the same way.
                $item_start = $item_start_date->format(DATE_FORMAT_DATETIME);
                $item_end = date('Y-m-d H:i:s', $test);

                // Get intersection of current day and the node value's duration (as strings in $to_zone timezone).
                $entity->calendar_start = $item_start < $start ? $start : $item_start;
                $entity->calendar_end = !empty($item_end) ? ($item_end > $end ? $end : $item_end) : $node->calendar_start;

                // Make date objects
                $entity->calendar_start_date = date_create($entity->calendar_start, timezone_open($to_zone));
                $entity->calendar_end_date = date_create($entity->calendar_end, timezone_open($to_zone));

                // Change string timezones into
                // calendar_start and calendar_end are UTC dates as formatted strings
                $entity->calendar_start = date_format($entity->calendar_start_date, DATE_FORMAT_DATETIME);
                $entity->calendar_end = date_format($entity->calendar_end_date, DATE_FORMAT_DATETIME);
                $entity->calendar_all_day = date_is_all_day($entity->calendar_start, $entity->calendar_end, $granularity, $increment);

                unset($entity->calendar_fields);
                if (isset($entity) && (empty($entity->calendar_start))) {
                    // if no date for the node and no date in the item
                    // there is no way to display it on the calendar
                    unset($entity);
                } else {
                    $entity->date_id .= '.' . $pos;

                    $rows[] = $entity;
                    unset($entity);
                }
                date_modify($next, '+1 second');
                $now = date_format($next, DATE_FORMAT_DATE);
                $pos++;

            }
            return $rows;
        }
        else {
            $rows = array();

            $date_info = $this->date_argument->view->date_info;
            $item_start_date = $event->date_start;
            $item_end_date = $event->date_end;
            $to_zone = $event->to_zone;
            $db_tz = $event->db_tz;
            $granularity = $event->granularity;
            $increment = $event->increment;

            // Now that we have an 'entity' for each view result, we need
            // to remove anything outside the view date range,
            // and possibly create additional nodes so that we have a 'node'
            // for each day that this item occupies in this view.
            $now = max($date_info->min_zone_string, $item_start_date->format(DATE_FORMAT_DATE));
            $to  = min($date_info->max_zone_string, $item_end_date->format(DATE_FORMAT_DATE));
            $next = new DateObject($now . ' 00:00:00', $date_info->display_timezone);
            if ($date_info->display_timezone_name != $to_zone) {
                // Make $start and $end (derived from $node) use the timezone $to_zone, just as the original dates do.
                date_timezone_set($next, timezone_open($to_zone));
            }
            if (empty($to) || $now > $to) {
                $to = $now;
            }
            // $now and $next are midnight (in display timezone) on the first day where node will occur.
            // $to is midnight on the last day where node will occur.
            // All three were limited by the min-max date range of the view.
            $pos = 0;
            while (!empty($now) && $now <= $to) {
                $entity = clone($event);

                // Get start and end of current day.
                $start = $next->format(DATE_FORMAT_DATETIME);
                date_modify($next, '+1 day');
                date_modify($next, '-1 second');
                $end = $next->format(DATE_FORMAT_DATETIME);

                // Get start and end of item, formatted the same way.
                $item_start = $item_start_date->format(DATE_FORMAT_DATETIME);
                $item_end = $item_end_date->format(DATE_FORMAT_DATETIME);

                // Get intersection of current day and the node value's duration (as strings in $to_zone timezone).
                $entity->calendar_start = $item_start < $start ? $start : $item_start;
                $entity->calendar_end = !empty($item_end) ? ($item_end > $end ? $end : $item_end) : $node->calendar_start;

                // Make date objects
                $entity->calendar_start_date = date_create($entity->calendar_start, timezone_open($to_zone));
                $entity->calendar_end_date = date_create($entity->calendar_end, timezone_open($to_zone));

                // Change string timezones into
                // calendar_start and calendar_end are UTC dates as formatted strings
                $entity->calendar_start = date_format($entity->calendar_start_date, DATE_FORMAT_DATETIME);
                $entity->calendar_end = date_format($entity->calendar_end_date, DATE_FORMAT_DATETIME);
                $entity->calendar_all_day = date_is_all_day($entity->calendar_start, $entity->calendar_end, $granularity, $increment);

                unset($entity->calendar_fields);
                if (isset($entity) && (empty($entity->calendar_start))) {
                    // if no date for the node and no date in the item
                    // there is no way to display it on the calendar
                    unset($entity);
                }
                else {
                    $entity->date_id .= '.' . $pos;

                    $rows[] = $entity;
                    unset($entity);
                }
                date_modify($next, '+1 second');
                $now = date_format($next, DATE_FORMAT_DATE);
                $pos++;

            }
            return $rows;
        }
    }
}