<?php
/**
 * @file
 * feature_newsletter.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function feature_newsletter_taxonomy_default_vocabularies() {
  return array(
    'newsletter_categories' => array(
      'name' => 'Newsletter categories',
      'machine_name' => 'newsletter_categories',
      'description' => 'Vocabulary used to store the categories of newsletter lists',
      'hierarchy' => '0',
      'module' => 'newsletter',
      'weight' => '0',
      'language' => 'und',
      'i18n_mode' => '0',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
