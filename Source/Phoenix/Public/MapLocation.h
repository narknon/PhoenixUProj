#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "MarkupData.h"
#include "MapLocation.generated.h"

class AMapLocationActor;
class UMapLocation;
class UMapMarkupComponent;

UCLASS(Blueprintable)
class UMapLocation : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AMapLocationActor* locationActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMapMarkupComponent* MapMarkupComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMapLocation*> Children;
    
public:
    UMapLocation();
    UFUNCTION(BlueprintCallable)
    void SetParent(UMapLocation* ParentIn);
    
    UFUNCTION(BlueprintCallable)
    void SetIsPrimary(bool IsPrimaryIn);
    
    UFUNCTION(BlueprintCallable)
    UMapLocation* RemoveLocation(UMapLocation* LocationIn);
    
    UFUNCTION(BlueprintCallable)
    bool IsRoot();
    
    UFUNCTION(BlueprintCallable)
    bool IsPrimary();
    
    UFUNCTION(BlueprintCallable)
    float GetVolume();
    
    UFUNCTION(BlueprintCallable)
    FRotator GetRotation();
    
    UFUNCTION(BlueprintCallable)
    UMapLocation* GetPrimaryInTree();
    
    UFUNCTION(BlueprintCallable)
    UMapLocation* GetParent();
    
    UFUNCTION(BlueprintCallable)
    UMapMarkupComponent* GetMapMarkupComponent();
    
    UFUNCTION(BlueprintCallable)
    FString GetLocationId();
    
    UFUNCTION(BlueprintCallable)
    UMapLocation* GetLocationByName(const FString& LocationName);
    
    UFUNCTION(BlueprintCallable)
    AMapLocationActor* GetLocationActor();
    
    UFUNCTION(BlueprintCallable)
    FVector GetLocation();
    
    UFUNCTION(BlueprintCallable)
    FVector GetExtent();
    
    UFUNCTION(BlueprintCallable)
    TArray<UMapLocation*> GetChildren();
    
    UFUNCTION(BlueprintCallable)
    FVector GetCenter();
    
    UFUNCTION(BlueprintCallable)
    int32 Depth();
    
    UFUNCTION(BlueprintCallable)
    static UMapLocation* CreateLocationUsingComponent(const FString& RegionIn, AMapLocationActor* LocationActorIn, FMarkupData MarkupDataIn);
    
    UFUNCTION(BlueprintCallable)
    static UMapLocation* CreateLocation(const FString& RegionIn, const FString& LocationIdIn, FVector LocationIn, FVector ExtentIn, FRotator RotationIn, FMarkupData MarkupDataIn);
    
    UFUNCTION(BlueprintCallable)
    bool ContainsPoint(FVector Point);
    
    UFUNCTION(BlueprintCallable)
    bool ContainsLocation(const FString& LocationIdIn);
    
    UFUNCTION(BlueprintCallable)
    bool AddLocation(UMapLocation* MapLocation);
    
};

