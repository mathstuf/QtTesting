/*
 * Copyright 2004 Sandia Corporation.
 * Under the terms of Contract DE-AC04-94AL85000, there is a non-exclusive
 * license for use of this work by or on behalf of the
 * U.S. Government. Redistribution and use in source and binary forms, with
 * or without modification, are permitted provided that this Notice and any
 * statement of authorship are reproduced on all copies.
 */

#include "pqAbstractActivateEventPlayer.h"

#include <QAction>
#include <QPushButton>

pqAbstractActivateEventPlayer::pqAbstractActivateEventPlayer()
{
}

bool pqAbstractActivateEventPlayer::playEvent(QObject* Object, const QString& Command, const QString& Arguments)
{
  if(Command != "activate")
    return false;

  if(QAction* const object = qobject_cast<QAction*>(Object))
    {
    object->activate(QAction::Trigger);
    return true;
    }

  if(QPushButton* const object = qobject_cast<QPushButton*>(Object))
    {
    object->click();
    return true;
    }

  return false;
}
