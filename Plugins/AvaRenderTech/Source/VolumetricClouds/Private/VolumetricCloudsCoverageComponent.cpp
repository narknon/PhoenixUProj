#include "VolumetricCloudsCoverageComponent.h"

UVolumetricCloudsCoverageComponent::UVolumetricCloudsCoverageComponent() {
    this->ShapeType = ECoverageShapeType::SPHERE;
    this->InnerRadius = 500.00f;
    this->InnerRadiusCoverage = 0.00f;
    this->OuterRadius = 1000.00f;
    this->OuterRadiusCoverage = 0.00f;
}

