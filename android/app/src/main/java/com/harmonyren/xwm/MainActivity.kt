package com.harmonyren.xwm

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.WindowManager
import androidx.core.view.WindowCompat
import androidx.core.view.WindowInsetsCompat
import androidx.core.view.WindowInsetsControllerCompat
import com.harmonyren.xwm.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        WindowCompat.setDecorFitsSystemWindows(window, false)

        window.attributes.layoutInDisplayCutoutMode =
            WindowManager.LayoutParams.LAYOUT_IN_DISPLAY_CUTOUT_MODE_SHORT_EDGES

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        binding.msgBox.text = startup()

        enterImmersiveMode()
    }

    private fun enterImmersiveMode() {
        val controller = WindowInsetsControllerCompat(window, window.decorView)
        controller.hide(WindowInsetsCompat.Type.systemBars())
        controller.systemBarsBehavior =
            WindowInsetsControllerCompat.BEHAVIOR_SHOW_TRANSIENT_BARS_BY_SWIPE

        window.decorView.systemUiVisibility = (
                android.view.View.SYSTEM_UI_FLAG_LAYOUT_STABLE
                        or android.view.View.SYSTEM_UI_FLAG_LAYOUT_HIDE_NAVIGATION
                        or android.view.View.SYSTEM_UI_FLAG_LAYOUT_FULLSCREEN
                        or android.view.View.SYSTEM_UI_FLAG_HIDE_NAVIGATION
                        or android.view.View.SYSTEM_UI_FLAG_FULLSCREEN
                        or android.view.View.SYSTEM_UI_FLAG_IMMERSIVE_STICKY
                )
    }

    external fun startup(): String

    companion object {
        init { System.loadLibrary("xwm") }
    }
}
