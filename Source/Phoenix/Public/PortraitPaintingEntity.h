#pragma once
#include "CoreMinimal.h"
#include "EPortraitPaintingEntitySource.h"
#include "PortraitPaintingEntity.generated.h"

class AActor;
class UPortraitPaintingEntityComponent;

USTRUCT(BlueprintType)
struct FPortraitPaintingEntity {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString EntityName;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> EntityActor;
    
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPortraitPaintingEntityComponent> EntityComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPortraitPaintingEntitySource Source;
    
    PHOENIX_API FPortraitPaintingEntity();
};

