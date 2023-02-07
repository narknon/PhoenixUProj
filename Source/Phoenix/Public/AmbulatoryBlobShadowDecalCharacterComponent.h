#pragma once
#include "CoreMinimal.h"
#include "SimpleBlobShadowDecalCharacterComponent.h"
#include "AmbulatoryBlobShadowDecalCharacterComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UAmbulatoryBlobShadowDecalCharacterComponent : public USimpleBlobShadowDecalCharacterComponent {
    GENERATED_BODY()
public:
    UAmbulatoryBlobShadowDecalCharacterComponent();
};

