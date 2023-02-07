#pragma once
#include "CoreMinimal.h"
#include "CompanionVolumeEntry.generated.h"

class AActor;
class APawn;

USTRUCT(BlueprintType)
struct FCompanionVolumeEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* Volume;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<APawn> Pawn;
    
    PHOENIX_API FCompanionVolumeEntry();
};

