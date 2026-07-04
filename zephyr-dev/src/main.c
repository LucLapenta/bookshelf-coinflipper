#include <zephyr/kernel.h>
#include <zephyr/drivers/uart.h>
#include <zephyr/sys/printk.h>
#include <zephyr/random/random.h>

BUILD_ASSERT(DT_NODE_HAS_COMPAT(DT_CHOSEN(zephyr_console), zephyr_cdc_acm_uart),
	     "Console device is not ACM CDC UART device");

int main(void)
{
	const struct device *const dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_console));
	uint32_t dtr = 0;
	uint8_t random_value;

	char heads[] = "HEADS";
	char tails[] = "TAILS";

	while (dtr) {
		uart_line_ctrl_get(dev, UART_LINE_CTRL_DTR, &dtr);
		k_sleep(K_MSEC(100));
	}

	while (1) {
		random_value = sys_rand8_get();

		if (random_value > 128) {
			printk("Coin Flip Result: %s", heads);

		} else {
			printk("Coin Flip Result: %s", tails);
		}
		k_sleep(K_SECONDS(1));
	}
	return 0;
}
