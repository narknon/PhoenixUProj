#pragma once
#include "CoreMinimal.h"
#include "BaseObjectCopyComponent.h"
#include "TransfigurationObjectCopyComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class PHOENIX_API UTransfigurationObjectCopyComponent : public UBaseObjectCopyComponent {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 UID;
    
    UTransfigurationObjectCopyComponent();
};

