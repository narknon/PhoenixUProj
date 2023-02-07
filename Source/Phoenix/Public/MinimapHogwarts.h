#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "MinimapBase.h"
#include "MinimapHogwarts.generated.h"

class UDataTable;
class UObject;
class UTexture2D;

UCLASS(Blueprintable, EditInlineNew)
class UMinimapHogwarts : public UMinimapBase {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* ZLevelData;
    
public:
    UMinimapHogwarts();
    UFUNCTION(BlueprintCallable)
    void TextureLoadedCallback(UTexture2D* Texture, UObject* Param);
    
    UFUNCTION(BlueprintCallable)
    void SetCurrentFloor(int32 Floor);
    
    UFUNCTION(BlueprintCallable)
    void Init(bool LoadNavMesh);
    
    UFUNCTION(BlueprintCallable)
    FVector2D GetTopLeftBound();
    
    UFUNCTION(BlueprintCallable)
    FVector GetDebugPlayerOffset();
    
    UFUNCTION(BlueprintCallable)
    int32 GetCurrentFloor();
    
    UFUNCTION(BlueprintCallable)
    FVector2D GetBottomRightBound();
    
    UFUNCTION(BlueprintCallable)
    void ChangeLevel(int32 LevelIndex, bool fromInit);
    
};

