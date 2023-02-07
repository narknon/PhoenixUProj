#pragma once
#include "CoreMinimal.h"
#include "WorldFXGenericManageSettings.h"
#include "WorldFXOctreeFX.h"
#include "WorldFXOctreeFXGenericManaged.generated.h"

class UActorComponent;

UCLASS(Blueprintable, NonTransient)
class WORLDFX_API UWorldFXOctreeFXGenericManaged : public UWorldFXOctreeFX {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UActorComponent> ActorComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWorldFXGenericManageSettings Manage;
    
    UWorldFXOctreeFXGenericManaged();
};

