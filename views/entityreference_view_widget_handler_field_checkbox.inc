<?php

/**
* @file
* Views field handler. Contains all relevant VBO options and related logic.
* Implements the Views Form API.
*/

class entityreference_view_widget_handler_field_checkbox extends views_handler_field {
  var $revision = FALSE;

  function render($values) {
    $entity_id = $values->{$this->view->base_field};
    if (empty($entity_id)) {
      return;
    }
    return '<!--entityreference-view-widget-action-' . $entity_id . '-->';
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['ervw'] = array(
      'contains' => array(
        'force_single' => array('default' => FALSE),
      ),
    );
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['ervw'] = array(
      '#type' => 'fieldset',
      '#title' => t('Entity Reference Views Widget'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );

    $form['ervw']['force_single'] = array(
      '#type' => 'checkbox',
      '#title' => t('Force single'),
      '#default_value' => $this->options['ervw']['force_single'],
      '#description' => t('Check this box to restrict selection to a single value.'),
    );
  }
}
