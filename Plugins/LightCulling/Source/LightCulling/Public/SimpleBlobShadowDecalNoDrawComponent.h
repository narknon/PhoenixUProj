#pragma once
#include "CoreMinimal.h"
#include "SimpleBlobShadowDecalComponent.h"
#include "SimpleBlobShadowDecalNoDrawComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class USimpleBlobShadowDecalNoDrawComponent : public USimpleBlobShadowDecalComponent {
    GENERATED_BODY()
public:
    USimpleBlobShadowDecalNoDrawComponent();
};

