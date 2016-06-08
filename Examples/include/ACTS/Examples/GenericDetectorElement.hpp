// This file is part of the ACTS project.
//
// Copyright (C) 2016 ACTS project team
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

///////////////////////////////////////////////////////////////////
// GenericDetectorElement.h, ACTS project, Generic Detector plugin
///////////////////////////////////////////////////////////////////

#ifndef AGD_GENERICDETECTORELEMENT_GENERICDETECTORELEMENT
#define AGD_GENERICDETECTORELEMENT_GENERICDETECTORELEMENT 1

// Algebra and Identifier
#include "ACTS/Utilities/Definitions.hpp"
#include "ACTS/Utilities/Identifier.hpp"
// Geometry module
#include "ACTS/Detector/DetectorElementBase.hpp"

namespace Acts {

class Surface;
class PlanarBounds;
class DiscBounds;
class SurfaceMaterial;

/** @class GenericDetectorElement

 This is a lightweight type of detector element,
 it simply implements the base class.


 */

class GenericDetectorElement : public DetectorElementBase
{
public:
  /** Constructor for single sided detector element - bound to a Plane Surface
   */
  GenericDetectorElement(const Identifier                       identifier,
                         std::shared_ptr<Transform3D>           transform,
                         std::shared_ptr<const PlanarBounds>    pBounds,
                         double                                 thickness,
                         std::shared_ptr<const SurfaceMaterial> material
                         = nullptr);

  /** Constructor for single sided detector element - bound to a Plane Surface /
   * Disc Surface */
  GenericDetectorElement(const Identifier                       identifier,
                         std::shared_ptr<Transform3D>           transform,
                         std::shared_ptr<const DiscBounds>      dBounds,
                         double                                 thickness,
                         std::shared_ptr<const SurfaceMaterial> material
                         = nullptr);

  /**  Destructor */
  ~GenericDetectorElement();

  /** Identifier */
  Identifier
  identify() const override;

  /** Return local to global transform associated with this identifier*/
  const Transform3D&
  transform(const Identifier& identifier = Identifier()) const override;

  /** Return surface associated with this identifier, which should come from the
   */
  const Surface&
  surface(const Identifier& identifier = Identifier()) const override;

  /** Returns the full list of all detection surfaces associated to this
   * detector element */
  const std::vector<std::shared_ptr<const Surface>>&
  surfaces() const override;

  /** Return the boundaries of the surface associated with this identifier */
  const SurfaceBounds&
  bounds(const Identifier& identifier = Identifier()) const override;

  /** Return the center of the surface associated with this identifier
   In the case of silicon it returns the same as center()*/
  const Vector3D&
  center(const Identifier& identifier = Identifier()) const override;

  /** Return the normal of the surface associated with this identifier
   In the case of silicon it returns the same as normal()*/
  const Vector3D&
  normal(const Identifier& identifier = Identifier()) const override;

  /** The maximal thickness of the detector element outside the surface
   * dimension */
  double
  thickness() const override;

private:
  // the element representation
  Identifier                   m_elementIdentifier;
  std::shared_ptr<Transform3D> m_elementTransform;
  const SurfaceBounds*         m_elementBounds;

  std::shared_ptr<const Surface> m_elementSurface;
  double                         m_elementThickness;

  // the cache
  Vector3D                                    m_elementCenter;
  Vector3D                                    m_elementNormal;
  std::vector<std::shared_ptr<const Surface>> m_elementSurfaces;

  std::shared_ptr<const PlanarBounds> m_elementPlanarBounds;
  std::shared_ptr<const DiscBounds>   m_elementDiscBounds;
};

inline Identifier
GenericDetectorElement::identify() const
{
  return m_elementIdentifier;
}

inline const Transform3D&
GenericDetectorElement::transform(const Identifier&) const
{
  return *m_elementTransform;
}

inline const Surface&
GenericDetectorElement::surface(const Identifier&) const
{
  return *m_elementSurface;
}

inline const std::vector<std::shared_ptr<const Surface>>&
GenericDetectorElement::surfaces() const
{
  return m_elementSurfaces;
}

inline const SurfaceBounds&
GenericDetectorElement::bounds(const Identifier&) const
{
  return *m_elementBounds;
}

inline const Vector3D&
GenericDetectorElement::center(const Identifier&) const
{
  return m_elementCenter;
}

inline const Vector3D&
GenericDetectorElement::normal(const Identifier&) const
{
  return m_elementNormal;
}

inline double
GenericDetectorElement::thickness() const
{
  return m_elementThickness;
}

}  // end of ns

#endif