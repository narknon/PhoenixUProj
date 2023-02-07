#pragma once
#include "CoreMinimal.h"
#include "SimpleBlobShadowDecalComponent.h"
#include "SimpleBlobShadowDecalCharacterComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LIGHTCULLING_API USimpleBlobShadowDecalCharacterComponent : public USimpleBlobShadowDecalComponent {
    GENERATED_BODY()
public:
    USimpleBlobShadowDecalCharacterComponent();
};

