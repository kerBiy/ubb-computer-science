#pragma once

#include <assert.h>

#include "entity.h"
#include "repository.h"
#include "service.h"

/*
Tests some cases for the entity
*/
void entityTests();

/*
Tests some cases for the repo
*/
void repoTests();

/*
Tests some cases for the service
*/
void serviceTests();

/*
Run all the tests from the test module
*/
void runTests();