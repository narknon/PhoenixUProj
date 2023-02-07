#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SimpleBlobShadowDecalComponentEntry.generated.h"

class AActor;
class UMaterialInterface;
class UMovementComponent;
class USimpleBlobShadowDecalComponent;

USTRUCT(BlueprintType)
struct FSimpleBlobShadowDecalComponentEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseActorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> ActorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIncludeActorSubclasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseMovementComponentClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UMovementComponent> MovementComponentClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIncludeMovementComponentSubclasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USimpleBlobShadowDecalComponent> BlobShadowDecalComponentClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* OverrideDecalMaterial;
    
    LIGHTCULLING_API FSimpleBlobShadowDecalComponentEntry();
};

