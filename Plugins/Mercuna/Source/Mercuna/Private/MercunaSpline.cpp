#include "MercunaSpline.h"

bool UMercunaSpline::IsValid() const {
    return false;
}

bool UMercunaSpline::IsReady() const {
    return false;
}

bool UMercunaSpline::IsPartial() const {
    return false;
}

TArray<FSplinePoint> UMercunaSpline::GetSplinePoints() const {
    return TArray<FSplinePoint>();
}

FVector UMercunaSpline::GetPathPoint(int32 I) const {
    return FVector{};
}

int32 UMercunaSpline::GetNumPathPoints() const {
    return 0;
}

float UMercunaSpline::GetLength() const {
    return 0.0f;
}

UMercunaSpline::UMercunaSpline() {
}

