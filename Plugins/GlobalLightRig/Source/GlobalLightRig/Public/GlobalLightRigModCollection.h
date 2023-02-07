#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GlobalLightRigModCollection.generated.h"

class UGlobalLightRigMod;

UCLASS(Blueprintable)
class UGlobalLightRigModCollection : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UGlobalLightRigMod*> Mods;
    
    UGlobalLightRigModCollection();
};

