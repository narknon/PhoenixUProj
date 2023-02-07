#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "LODViewerInfos.h"
#include "LODViewerManager.generated.h"

class UPhoenixSignificanceManager;
class USkeletalMesh;
class USkeletalMeshComponent;

UCLASS(Blueprintable)
class ULODViewerManager : public UObject {
    GENERATED_BODY()
public:
    ULODViewerManager();
    UFUNCTION(BlueprintCallable)
    static TArray<FString> PopulateListOfSkeletalMeshes();
    
    UFUNCTION(BlueprintCallable)
    static int32 GetSkeletalMeshPredictedLODLevel(USkeletalMeshComponent* SkeletalMeshComponent);
    
    UFUNCTION(BlueprintCallable)
    static FName GetObjectPathByString(const FString& AssetName);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetNumLODsForViewer(USkeletalMesh* SkeletalMesh);
    
    UFUNCTION(BlueprintCallable)
    static TArray<FLODViewerInfos> GetLODInfoFromSkeletalMesh(USkeletalMesh* SkeletalMesh);
    
    UFUNCTION(BlueprintCallable)
    static float ComputeScreenRadius(const FVector& Origin, const float Radius, const FVector& ViewOrigin, UPhoenixSignificanceManager* SigManager);
    
    UFUNCTION(BlueprintCallable)
    static float ComputePixelsOnScreen(float ScreenDiameter, float ResolutionMax);
    
    UFUNCTION(BlueprintCallable)
    static TArray<float> CalculateLODDistancesFromSphereRadius(TArray<float> LODScreenSizes, float Radius, UPhoenixSignificanceManager* SigManager);
    
};

