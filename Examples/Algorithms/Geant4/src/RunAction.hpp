// This file is part of the Acts project.
//
// Copyright (C) 2017-2020 CERN for the benefit of the Acts project
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#include <G4UserRunAction.hh>
#include <globals.hh>
#include <memory>

class G4Run;

namespace ActsExamples {

/// @class RunAction
///
/// @brief The material mapping run action
///
/// The RunAction class is the implementation of the
/// Geant4 class G4UserRunAction. It initiates the run
/// an resets the EventAction
class RunAction final : public G4UserRunAction {
 public:
  /// Static access method
  static RunAction* instance();

  /// Construct the action and ensure singleton usage.
  RunAction();
  ~RunAction() final override;

  /// Interface method at the begin of the run
  /// @note resets the event action
  void BeginOfRunAction(const G4Run*) final override;

  /// Interface method at the end of the run
  void EndOfRunAction(const G4Run*) final override;

 private:
  /// Instance of the EventAction
  static RunAction* s_instance;
};

}  // namespace ActsExamples
