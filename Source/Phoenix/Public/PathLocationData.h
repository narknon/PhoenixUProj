#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PathLocationData.generated.h"

class AMapLocationActor;
class UMapLocation;
class UMapMarkupComponent;

USTRUCT(BlueprintType)
struct FPathLocationData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMapMarkupComponent* Room;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMapLocation* Floor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMapMarkupComponent* Stair;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMapLocation* Primary;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AMapLocationActor* PrimaryStructureLocationActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector PathPoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bISinglePrimaryLocation;
    
    PHOENIX_API FPathLocationData();
};

