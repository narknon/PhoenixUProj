#pragma once
#include "CoreMinimal.h"
#include "MaterialPreLoadKeysActor.h"
#include "MaterialPreLoadKeysActorListActor.generated.h"

class AActor;

UCLASS(Blueprintable)
class AMaterialPreLoadKeysActorListActor : public AMaterialPreLoadKeysActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> ForActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAttachedChildren;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bComponentChildren;
    
    AMaterialPreLoadKeysActorListActor(const FObjectInitializer& ObjectInitializer);
};

