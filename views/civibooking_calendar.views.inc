<?php

/**
 * Implements hook_views_data_alter().
 *
 * Return $data to hook_views_data*/

function civibooking_calendar_views_data_alter(&$data) {

    $data['civicrm_booking']['id']['help'] = t('id');
    $data['civicrm_booking']['id']['help'] = t('id');
    $data['civicrm_booking']['date_argument']['argument']['handler'] = 'civibooking_calendar_date_views_argument_handler';

    $data['civicrm_booking']['title'] = array(
        'title' => t('title'),
        'help' => t('title'),
        'real field' => 'title',
        'field' => array(
            'handler' => 'views_handler_field',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_handler_argument_string',
            'name field' => 'title',
            'numeric' => FALSE
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_string',
            'help' => t('booked title'),
        ),
        'sort' => array(
            'handler' => 'views_handler_sort',
            'help' => t('Sort on CiviCRM Booking title field.'),
        ),
    );

    $data['civicrm_booking']['status_id'] = array(
        'title' => t('Status ID'),
        'help' => t('Status ID'),
        'real field' => 'status_id',
        'field' => array(
            'handler' => 'views_handler_field_numeric',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_handler_argument_numeric',
            'name field' => 'status id',
            'numeric' => FALSE
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_numeric',
            'help' => t('Filter on CiviCRM Booking Status ID field.'),
        ),
        'sort' => array(
            'handler' => 'views_handler_sort',
            'help' => t('Sort on CiviCRM Booking Status ID field.'),
        ),
    );

    $data['civicrm_booking']['booking_date']['help'] = t('Booked Date');
    $data['civicrm_booking']['booking_date']['filter']['help'] = t('Filter on CiviCRM Booking Booking Date field.');
    $data['civicrm_booking']['booking_date']['sort']['help'] = t('Sort on CiviCRM Booking Booking Date field.');


    $data['civicrm_booking']['start_date'] = array(
        'title' => t('Start Date'),
        'help' => t('Start Date'),
        'real field' => 'start_date',
        'field' => array(
            'handler' => 'civicrm_handler_field_datetime',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_handler_argument_date',
            'name field' => 'start date',
            'numeric' => FALSE
        ),
        'filter' => array(
            'handler' => 'civicrm_handler_filter_datetime',
            'help' => t('Filter on CiviCRM Booking Start Date field.'),
        ),
        'sort' => array(
            'handler' => 'civicrm_handler_sort_datetime',
            'help' => t('Sort on CiviCRM Booking Start Date field.'),
        ),
    );

    $data['civicrm_booking']['end_date'] = array(
        'title' => t('End Date'),
        'help' => t('End Date'),
        'real field' => 'end_date',
        'field' => array(
            'handler' => 'civicrm_handler_field_datetime',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_handler_argument_date',
            'name field' => 'end date',
            'numeric' => FALSE
        ),
        'filter' => array(
            'handler' => 'civicrm_handler_filter_datetime',
            'help' => t('Filter on CiviCRM Booking End Date field.'),
        ),
        'sort' => array(
            'handler' => 'civicrm_handler_sort_datetime',
            'help' => t('Sort on CiviCRM Booking End Date field.'),
        ),
    );

    $data['civicrm_booking']['po_number'] = array(
        'title' => t('Po Number'),
        'help' => t('Po Number'),
        'real field' => 'po_number',
        'field' => array(
            'handler' => 'views_handler_field',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_handler_argument_string',
            'name field' => 'po_number',
            'numeric' => FALSE
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_string',
            'help' => t('Filter on CiviCRM Booking Po number field.'),
        ),
        'sort' => array(
            'handler' => 'views_handler_sort',
            'help' => t('Sort on CiviCRM Booking Po Number field.'),
        ),
    );

    $data['civicrm_booking']['total_amount'] = array(
        'title' => t('Total Amount'),
        'help' => t('Total Amount'),
        'real field' => 'total_amount',
        'field' => array(
            'handler' => 'views_handler_field_numeric',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_handler_argument_numeric',
            'name field' => 'total_amount',
            'numeric' => FALSE
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_numeric',
            'help' => t('Filter on CiviCRM Booking Total Amount field.'),
        ),
        'sort' => array(
            'handler' => 'views_handler_sort',
            'help' => t('Sort on CiviCRM Booking Total Amount field.'),
        ),
    );

    $data['civicrm_booking']['description']['help'] = t('Description');
    $data['civicrm_booking']['description']['filter']['help'] = t('Description');
    $data['civicrm_booking']['description']['sort']['help'] = t('Description');

    $data['civicrm_booking']['note']['help'] = t('Note');
    $data['civicrm_booking']['note']['filter']['help'] = t('Note');
    $data['civicrm_booking']['note']['sort']['help'] = t('Note');

    $data['civicrm_booking']['adhoc_charges_note']['help'] = t('Adhoc Charges Note');
    $data['civicrm_booking']['adhoc_charges_note']['filter']['help'] = t('Adhoc Charges Note');
    $data['civicrm_booking']['adhoc_charges_note']['sort']['help'] = t('Adhoc Charges Note');

    $data['civicrm_booking']['participants_estimate']['help'] = t('Participants Estimate');
    $data['civicrm_booking']['participants_estimate']['filter']['help'] = t('Participants Estimate');
    $data['civicrm_booking']['participants_estimate']['sort']['help'] = t('Participants Estimate');

    $data['civicrm_booking']['participants_actual']['help'] = t('Participants Actual');
    $data['civicrm_booking']['participants_actual']['filter']['help'] = t('Participants Actual');
    $data['civicrm_booking']['participants_actual']['sort']['help'] = t('Participants Actual');

    $data['civicrm_booking']['discount_amount']['help'] = t('Discount Amount');
    $data['civicrm_booking']['discount_amount']['filter']['help'] = t('Discount Amount');
    $data['civicrm_booking']['discount_amount']['sort']['help'] = t('Discount Amount');

    $data['civicrm_booking']['is_deleted'] = array(
        'title' => t('Is Deleted'),
        'help' => t('Is Deleted'),
        'real field' => 'is_deleted',
        'field' => array(
            'handler' => 'views_handler_field_boolean',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_handler_argument_boolean',
            'name field' => 'is_deleted',
            'numeric' => FALSE
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_boolean',
            'help' => t('Filter on CiviCRM Booking Is Deleted field.'),
        ),
        'sort' => array(
            'handler' => 'views_handler_sort',
            'help' => t('Sort on CiviCRM Booking Is Deleted field.'),
        ),
    );

    $data['civicrm_booking']['created_by']['help'] = t('Created By');
    $data['civicrm_booking']['created_by']['filter']['help'] = t('Created By');
    $data['civicrm_booking']['created_by']['sort']['help'] = t('Created By');

    $data['civicrm_booking']['created_date']['help'] = t('Created Date');
    $data['civicrm_booking']['created_date']['filter']['help'] = t('Created Date');
    $data['civicrm_booking']['created_date']['sort']['help'] = t('Created Date');

    $data['civicrm_booking']['updated_by']['help'] = t('Updated By');
    $data['civicrm_booking']['updated_by']['filter']['help'] = t('Updated By');
    $data['civicrm_booking']['updated_by']['sort']['help'] = t('Updated By');

    $data['civicrm_booking']['updated_date']['help'] = t('Updated Date');
    $data['civicrm_booking']['updated_date']['filter']['help'] = t('Updated Date');
    $data['civicrm_booking']['updated_date']['sort']['help'] = t('Updated Date');

    //Create relationship by joining to CiviCRM Contacts
    $data['civicrm_booking']['primary_contact_id'] = array(
        'title' => t('Primary Contact ID'),
        'help' => t('Primary Contact ID'),
        'real field' => 'primary_contact_id',
        'field' => array(
            'handler' => 'views_handler_field_numeric',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_handler_argument_numeric',
            'name field' => 'primary_contact_id',
            'numeric' => FALSE
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_numeric',
            'help' => t('Filter on CiviCRM Booking Primary Contact ID field.'),
        ),
        'sort' => array(
            'handler' => 'views_handler_sort',
            'help' => t('Sort on CiviCRM Booking Primary Contact ID field.'),
        ),
        'relationship' => array(
            'handler' => 'views_handler_relationship',
            'base' => 'civicrm_contact',
            'base field' => 'id',
            'title' => t('CiviCRM Contact'),
            'label' => t('civicrm contact join'),
        ),
    );
}
