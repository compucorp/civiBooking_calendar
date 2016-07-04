Civibooking_calendar is a module that displays CiviBooking data on views calendar

Dependencies:
- civicrm
- civicrm_entity Download link: https://github.com/eileenmcnaughton/civicrm_entity
- date
- views
- calendar
- entity

To display bookings on Calendar:
   1. Go to "mysitename/admin/structure/views" and select "Add new from template"
   2. Search for 'start_date' field in the 'civicrm_booking' base table and click add.

To display resources on Calendar:
   1. Go to "mysitename/admin/structure/views" and select "Add new from template"
   2. Search for 'start' field in the 'civicrm_booking_slot' base table and click add.
