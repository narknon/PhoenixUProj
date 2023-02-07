#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "OnMercunaPathUpdatedDelegate.h"
#include "MercunaPath.generated.h"

UCLASS(Blueprintable)
class MERCUNA_API UMercunaPath : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnMercunaPathUpdated PathUpdated;
    
    UMercunaPath();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsValid() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsReady() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPartial() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetPoint(int32 I) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetPathLength() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumPoints() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetDebugInfo(int32& nodesUsed, bool& bOutOfNodes, float& queryTime) const;
    
};

