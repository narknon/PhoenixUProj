#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "MapData.generated.h"

class UMapData;
class UMapLocation;

UCLASS(Blueprintable)
class UMapData : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMapLocation* Root;
    
    UMapData();
    UFUNCTION(BlueprintCallable)
    UMapLocation* FindLocationThatContainsPoint(FVector Point, UMapLocation* StartLocation);
    
    UFUNCTION(BlueprintCallable)
    UMapLocation* FindLocationByName(const FString& Name, UMapLocation* StartLocation);
    
    UFUNCTION(BlueprintCallable)
    int32 FindDepthOfLocation(UMapLocation* LocationIn, UMapLocation* SearchRoot, int32 CurrentDepth);
    
    UFUNCTION(BlueprintCallable)
    static UMapData* CreateMapData();
    
    UFUNCTION(BlueprintCallable)
    bool ContainsLocation(const FString& LocationName);
    
    UFUNCTION(BlueprintCallable)
    bool AddLocationInternal(UMapLocation* MapLocation, UMapLocation* Parent);
    
    UFUNCTION(BlueprintCallable)
    bool AddLocation(UMapLocation* MapLocation);
    
};

